#include <bits/stdc++.h>
using namespace std;

char s[100000001];
int a[10000001];
int t = 0;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    int n = strlen(s+1);
    for(int i = 1;i <= n;i++){
        if(s[i] == '0'||s[i] == '1' || s[i] == '2'|| s[i] == '3'|| s[i] == '4'|| s[i] == '5'|| s[i] == '6'|| s[i] == '7'|| s[i] == '8'|| s[i] == '9'){
            a[++t] = s[i] - '0';
        }
    }
    sort(a+1,a+t+1);
    for(int i = t;i >= 1;i--){
        printf("%d",a[i]);
    }
    return 0;
}
