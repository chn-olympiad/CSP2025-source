#include <bits/stdc++.h>
using namespace std;
char str[2000000];
int num[20];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        if (str[i] >= '0' && str[i] <= '9'){
            num[str[i] - 48]++;
        }
    }
    for (int i = 9; i >= 0; i--){
        for (int j = 1; j <= num[i]; j++){
            printf("%d", i);
        }
    }
    fclose(stdin);
    fclose(stdout);
}
