#include<bits/stdc++.h>
using namespace std;

int n, m, l, no = 0, sum = 0, sum_all = 0;
int c[501], s[501];
char x[501];

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", x+1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &c[i]);
    }
    l = strlen(x+1);
    for(int i = 1; i <= l; i++){
        if(x[i] == '0') s[i] = 0;
        else s[i] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i; j++){
            if(c[j] > c[j+1]) swap(c[j], c[j+1]);
        }
    }
    for(int i = 1; i <= n; i++){
        if(s[i] == '0') no++,sum += 0;
        else{
            if(no >= c[i]) no++,sum += 0;
            else sum++,no += 0;
        }
        if(sum >= m) sum_all++;
    }
    printf("%d", sum_all);
    return 0;
}
