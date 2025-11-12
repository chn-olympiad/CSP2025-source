#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010],n[10]={0};
main(){
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    scanf("%s" , &s);
    int l = strlen(s);
    int ai = 0;
    for(int i = 0 ; i <= l ; i++){
        if(s[i] - '0' <= 9){
            ai++;
            a[ai] = s[i]-'0';
        }
    }
    for(int i = 1 ; i <= 10 ; i++) n[i]=0;
    for(int i = 1; i <= ai ; i++) n[a[i]]++;
    for(int i = 9 ; i >= 0 ; i--){
        for(int j = n[i] ; j >= 1 ; j--) cout<<i;
    }
    return 0;
}
