#include<bits/stdc++.h>

using namespace std;


char s[1000001];
int l,c = 0;
int a[1000001];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    l = strlen(s+1);
    for(int i = 1; i <= l; i++){
        if(s[i] - '0' <= 9){
            c++;
            a[c] = s[i] - '0';
        }
    }
    for(int i = 1; i <= c; i++){
        for(int j = 1; j <= c - i; j++){
            if(a[j] > a[j+1]){
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    for(int i = c; i >= 1; i--){
        printf("%d",a[i]);
    }
    return 0;
}
