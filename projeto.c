#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void maiusculo(char *string){
    int i;
    for (i = 0; string[i] != '\0'; i++){
        string[i] = toupper(string[i]);
    }
}

float Deposito(float ValorInicial, float deposito){
    return ValorInicial + deposito;
}

float Saque(float ValorInicial, float saque){
    return ValorInicial - saque;
}

void menu(){
    
    printf("            MENU         \n\n");
    printf("      1. Criar conta       \n");
    printf("       2. Depositar        \n");
    printf("         3. Sacar          \n");
    printf("         4. Sair           \n");
    printf("    5. Consultar conta   \n\n");
}

struct Conta{

    char nome [999];
    char DatadeNascimento[999];
    float Deposito;
    int NumerodaConta;

};

int main () {

    setlocale(LC_ALL, "portuguese");
    srand((unsigned int)time(NULL));

    struct Conta conta [100];
    char resposta [200];
    int i = 0, numerodigitado;
    float valordeDeposito, valordeSaque;
    int numero;


    menu();
    
    printf("Como deseja prosseguir? ");
    gets(resposta);
    maiusculo(resposta);
    system("cls || clear");
    
    while(strcmp(resposta, "SAIR") != 0 && strcmp(resposta, "4") != 0){
    	
    	while(strcmp(resposta, "1") == 0 || strcmp(resposta, "CRIAR CONTA") == 0){

            i++;
    		
    		printf("Nome completo: ");
            gets(conta[i].nome);
    		printf("Data de nascimento: ");
            gets(conta[i].DatadeNascimento);
    		printf("Deposito inicial: ");
            scanf("%f", &conta[i].Deposito);

            system("cls || clear");
            conta[i].NumerodaConta = rand() % 100;
            printf("Número da sua conta: %d", conta[i].NumerodaConta);
    		
            fflush(stdin);
    		getchar();
    		system("cls || clear");
    		strcpy(resposta, "MENU");
    		
		}

        while(strcmp(resposta, "2") == 0 || strcmp(resposta, "DEPOSITAR") == 0){

            printf("Número da conta: ");
            scanf("%d", &numerodigitado);

            fflush(stdin);
            system("cls || clear");
            for (i = 0; i < 100; i++){

                if(numerodigitado == conta[i].NumerodaConta){
                    numero = conta[i].NumerodaConta;

                    printf("Quanto deseja depositar? ");
                    scanf("%f", &valordeDeposito);
                    system("cls || clear");

                    fflush(stdin);
                    printf("Nome: %s\n", conta[i].nome);
                    printf("Data de Nascimento: %s\n", conta[i].DatadeNascimento);
                    conta[i].Deposito = Deposito(conta[i].Deposito, valordeDeposito);
                    printf("Conta atualizada: R$%.2f\n", conta[i].Deposito);
                    printf("Número da conta: %d\n", conta[i].NumerodaConta);

                    getchar();
                    system("cls || clear");
                    strcpy(resposta, "MENU");

                    break;

                } else {
                    numero = 999;
                }

            }
            
        }

        while (strcmp(resposta, "SACAR") == 0 || strcmp(resposta, "3") == 0){
            
            printf("Número da conta: ");
            scanf("%d", &numerodigitado);

            fflush(stdin);
            system("cls || clear");
            for (i = 0; i < 100; i++){

                if(numerodigitado == conta[i].NumerodaConta){
                    numero = conta[i].NumerodaConta;

                    printf("Quanto deseja sacar? ");
                    scanf("%f", &valordeSaque);
                    system("cls || clear");

                    fflush(stdin);
                    printf("Nome: %s\n", conta[i].nome);
                    printf("Data de Nascimento: %s\n", conta[i].DatadeNascimento);
                    conta[i].Deposito = Saque(conta[i].Deposito, valordeSaque);
                    printf("Conta atualizada: R$%.2f\n", conta[i].Deposito);
                    printf("Número da conta: %d\n", conta[i].NumerodaConta);

                    getchar();
                    system("cls || clear");
                    strcpy(resposta, "MENU");

                    break;

                } else {
                    numero = 999;
                }

            }

        }

        while (strcmp (resposta, "CONSULTAR CONTA") == 0 || strcmp(resposta, "5") == 0){
            
            printf("Número da conta: ");
            scanf("%d", &numerodigitado);

            fflush(stdin);
            system("cls || clear");
            for (i = 0; i < 100; i++){

                if(numerodigitado == conta[i].NumerodaConta){
                    numero = conta[i].NumerodaConta;
                    printf("Nome: %s\n", conta[i].nome);
                    printf("Data de Nascimento: %s\n", conta[i].DatadeNascimento);
                    printf("Saldo: R$%.2f\n", conta[i].Deposito);
                    printf("Número da conta: %d", conta[i].NumerodaConta);

                    getchar();
                    system("cls || clear");
                    strcpy(resposta, "MENU");
                }
            }

        }    

        while(strcmp(resposta, "MENU") == 0){

            menu();
            
            printf("Como deseja prosseguir? ");
            gets(resposta);
            maiusculo(resposta);
            system("cls || clear");

        }
    	
	}

    return 0;
}