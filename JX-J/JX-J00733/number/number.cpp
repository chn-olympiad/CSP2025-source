#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
char c[maxn + 1];
int num[maxn + 1];

bool compare(int a , int b){
    return a > b;
}

int main(){
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    scanf("%s" , c);
    int len = strlen(c);
    int l = 0;
    for (int i = 0 ; i < len ; i += 1){
        if (c[i] <= '9' && c[i] >= '0'){
            l += 1;
            num[l] = c[i] - '0';
        }
    }
    sort(num + 1 , num + l + 1 , compare);
    if (num[1] == 0){
        printf("0");
        return 0;
    }
    for (int i = 1 ; i <= l ; i += 1){
        printf("%d" , num[i]);
    }
    return 0;
}
