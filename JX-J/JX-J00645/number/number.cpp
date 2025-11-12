#include <bits/stdc++.h>
using namespace std;
char a[1000010];
int b[11];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",a+1);
    for(int i=1;i<=strlen(a+1);i++){
        if(a[i]>=48&&a[i]<=57){
            b[a[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=b[i];j++){
            printf("%d",i);
        }
    }
    return 0;
}
