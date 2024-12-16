#include <stdio.h>
#include <math.h>

//Основни данни

typedef struct
{
    
    double zaplata;
    double dopprihodi;
    
} Prihodi;

typedef struct
{
    double jili6niRazhodi;
    double hronaRazhodi;
    double transportRazhodi;
    double zdravniRazhodi;
    double zabaviRazhodi;
    double drugiRazhodi;
    
} Razhodi;

typedef struct
{
    double balans;
    double lihvi;
    
} Spestqvaniq;

// Функции за изчисления
double izchislqvanenaPrihRastej(Prihodi prihodi, int godini) {
    return (prihodi.zaplata + prihodi.dopprihodi) * godini;
}

double izcisliRashodi(double jili6niRazhodi,double hronaRazhodi,double transportRazhodi,double zdravniRazhodi,double zabaviRazhodi,double drugiRazhodi, int godini){
    double rezultat = (jili6niRazhodi + hronaRazhodi + transportRazhodi + zdravniRazhodi + zabaviRazhodi + drugiRazhodi)*godini;
    return rezultat;
}

void proporciiRazhodi( double jili6niRazhodi,double hronaRazhodi,double transportRazhodi,double zdravniRazhodi,double zabaviRazhodi,double drugiRazhodi) {
    double osnovnirazhodi = jili6niRazhodi + hronaRazhodi + transportRazhodi + zdravniRazhodi;
    double dopulnitelnirazhodi = zabaviRazhodi + drugiRazhodi;
    double obshtiRazhodi = osnovnirazhodi + dopulnitelnirazhodi;
    double proporciq = (osnovnirazhodi / obshtiRazhodi) * 100;
    printf("Основните разходи съставляват %.2f%% от общите разходи.\n", proporciq);
    if (proporciq < 80){
        printf("Препоръчително е да намалите вашите допълнителни разходи!\n");
    }
    else{
        printf("Поздрвления, вашите разходи са добре балансирани!\n");
    }
}

double izchislqvaneSlojnaLihva(Spestqvaniq spestqvaniq, int godini, double lihvi) {
    return spestqvaniq.balans * pow(1 + lihvi, godini);
}
double spestovenIzbor(int izbor2, Spestqvaniq spestqvaniq){
    switch (izbor2)
    {
    case 1:
        printf("Лихвен процент: Обикновено между 0.1%% и 2%% годишно\nОчаквана печалба: Тези сметки предлагат стабилност, но ниска възвръщаемост,\nтака че са подходящи за краткосрочни спестявания или спешен фонд.\n");
        printf("Въведете вашия лихвен процент (например 0.01 за 1%%): ");
        scanf("%lf", &spestqvaniq.lihvi);
        return spestqvaniq.lihvi;
    case 2:
        printf("Лихвен процент: 1%% до 5%% годишно, в зависимост от рейтинга на емитента (по-високи лихви за корпоративни облигации).\nОчаквана печалба: Това са стабилни инвестиции, особено държавните облигации, но възвръщаемостта може да бъде по-ниска от инвестициите в акции.\n");
        printf("Въведете вашия лихвен процент (например 0.01 за 1%%): ");
        scanf("%lf", &spestqvaniq.lihvi);
        return spestqvaniq.lihvi;
    case 3:
        printf("Лихвен процент/Очаквана възвръщаемост: Средно около 3%% до 6%% годишно.\nОчаквана печалба: Това са фондове, които инвестират в сравнително стабилни активи, като облигации и дивидентни акции.\nТе са подходящи за по-консервативни инвеститори.\n");
        printf("Въведете вашия лихвен процент (например 0.01 за 1%%): ");
        scanf("%lf", &spestqvaniq.lihvi);
        return spestqvaniq.lihvi;
    case 4:
        printf("Очаквана възвръщаемост: Обикновено около 4%% до 8%% годишно, като това включва както доход от наем, така и потенциално увеличение на стойността на имота.\nОчаквана печалба: В дългосрочен план недвижимите имоти са стабилни инвестиции, но изискват значителни начални средства.\n");
        printf("Въведете вашия лихвен процент (например 0.01 за 1%%): ");
        scanf("%lf", &spestqvaniq.lihvi);
        return spestqvaniq.lihvi;
    case 5:
        printf("Очаквана възвръщаемост: Около 1%% до 3%% годишно при стабилен растеж; може да нарасне повече по време на икономически несигурности.\nОчаквана печалба: Златото и другите метали обикновено запазват стойността си, но предлагат ниска доходност.\nТе служат като защитен актив в дългосрочен план.\n");
        printf("Въведете вашия лихвен процент (например 0.01 за 1%%): ");
        scanf("%lf", &spestqvaniq.lihvi);
        return spestqvaniq.lihvi;
    case 6:
        printf("Очаквана възвръщаемост: Високопроменлива; може да варира от -50%% до над 100%% в рамките на година.\nОчаквана печалба: Това е високорисков клас активи с възможност за огромни печалби или загуби.\nПодходящо е за инвеститори, готови да поемат значителен риск.\n");
        printf("Въведете вашия лихвен процент (например 0.01 за 1%%): ");
        scanf("%lf", &spestqvaniq.lihvi);
        return spestqvaniq.lihvi;
    case 7:
        printf("Парите няма да генерират никаква възвръщаемост (освен ако не се използват за инвестиции или покупки, които увеличават стойността си, например недвижими имоти или стоки).\nВъзможната печалба се ограничена от инфлацията, тъй като реалната стойност на парите намалява с времето.\n");
        return 0;
    default:
        printf("Грешен символ");
        break;
    }
}
Razhodi vavedeteRazhodi() {
    Razhodi razhodi;
    printf("Въведете разходи за жилище (наем, комунални услуги и т.н.): ");
    scanf("%lf", &razhodi.jili6niRazhodi);
    printf("Въведете разходи за храна: ");
    scanf("%lf", &razhodi.hronaRazhodi);
    printf("Въведете разходи за транспорт: ");
    scanf("%lf", &razhodi.transportRazhodi);
    printf("Въведете разходи за здравеопазване: ");
    scanf("%lf", &razhodi.zdravniRazhodi);
    printf("Въведете разходи за развлечения: ");
    scanf("%lf", &razhodi.zabaviRazhodi);
    printf("Въведете други разходи: ");
    scanf("%lf", &razhodi.drugiRazhodi);
    return razhodi;
}
void rekomendacii(double hronaRazhodi, double zabaviRazhodi) {
    if (hronaRazhodi > 500) {
        printf("Препоръка: Опитайте се да намалите разходите за храна, като готвите повече вкъщи.\n");
    }
    if (zabaviRazhodi > 200) {
        printf("Препоръка: Може да обмислите по-нискобюджетни развлечения като гледане на филми вкъщи.\n");
    }
}
// Основно меню
void displayMenu() {
    printf("=== Financial Planning and Forecasting ===\n");
    printf("1. Въведете приходи\n");
    printf("2. Въведете разходи\n");
    printf("3. Въведете спестявания\n");
    printf("4. Прогнозирайте финансовото състояние\n");
    printf("5. Изход\n");
    printf("Изберете опция: ");
}

int main() {
    Prihodi prihodi = {0, 0};
    Spestqvaniq spestqvaniq = {0, 0};
    Razhodi razhodi;
    int izbor, godini;
    while (1) {
        displayMenu();
        if(scanf("%d",&izbor) == 1){
            switch (izbor)
            {
            case 1:
                printf("Въведете месечна заплата: ");
                scanf("%lf", &prihodi.zaplata);
                printf("Въведете допълнителни приходи: ");
                scanf("%lf", &prihodi.dopprihodi);
                break;
            case 2:
                razhodi = vavedeteRazhodi();
                break;
            case 3:
                int izbor2;
                printf("Въведете текущи спестявания: ");
                scanf("%lf", &spestqvaniq.balans);
                printf("\nПод каква форма държите своите спестявания?\n");
                printf("1. Спестовна или депозитна сметка\n");
                printf("2. Инвестиции в акции\n");
                printf("3. Пенсионен фонд\n");
                printf("4. Недвижими имоти\n");
                printf("5. Злато или ценни метали\n");
                printf("6. Криптовалути\n");
                printf("7. Натрупана сума в брой\n");
                printf("Изберете опция: ");
                scanf("%d",&izbor2);
                double lihvi = spestovenIzbor(izbor2,spestqvaniq);
                break;
            case 4:
            if(izchislqvanenaPrihRastej(prihodi, godini) > izcisliRashodi(razhodi.jili6niRazhodi, razhodi.hronaRazhodi,razhodi.transportRazhodi,razhodi.zdravniRazhodi,razhodi.zabaviRazhodi,razhodi.drugiRazhodi,godini)){
                printf("Въведете брой години за прогнозиране: ");
                scanf("%d", &godini);
                double ichislenPrihod = izchislqvanenaPrihRastej(prihodi, godini);
                double izchisleniSpestqvaniq = izchislqvaneSlojnaLihva(spestqvaniq, godini, lihvi);
                printf("\n--- Финансово състояние след %d години ---\n", godini);
                printf("Прогнозирани приходи: %.2lf\n", ichislenPrihod);
                printf("Съотношения на разходи: %.2lf\n",izcisliRashodi(razhodi.jili6niRazhodi, razhodi.hronaRazhodi,razhodi.transportRazhodi,razhodi.zdravniRazhodi,razhodi.zabaviRazhodi,razhodi.drugiRazhodi,godini));
                proporciiRazhodi(razhodi.jili6niRazhodi, razhodi.hronaRazhodi,razhodi.transportRazhodi,razhodi.zdravniRazhodi,razhodi.zabaviRazhodi,razhodi.drugiRazhodi);
                printf("Прогнозирани спестявания: %.2lf\n", izchisleniSpestqvaniq);
                break;
            }
            else{
                printf("-----------------------------------------------------------------------------------------\n");
                printf("Спешно трябва да предприемете мерки да повишите приходите си или да намалите разходите си!\n");
                double rez = izchislqvanenaPrihRastej(prihodi, godini) - izcisliRashodi(razhodi.jili6niRazhodi, razhodi.hronaRazhodi,razhodi.transportRazhodi,razhodi.zdravniRazhodi,razhodi.zabaviRazhodi,razhodi.drugiRazhodi,godini);
                printf("Не можете да покриете: %lf\n",rez);
                printf("-----------------------------------------------------------------------------------------\n");

                break;
            }
            case 5:
                printf("Изход от програмата...\n");
                    return 0;
            default:
                printf("Грешен символ");
                break;
            }
        }
        else{
            printf("Грешен символ");
            break;
        }
    }
    return 0;
}