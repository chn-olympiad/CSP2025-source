#include <bits/stdc++.h>
using namespace std;
const int N=1000010;
int book[14];
char c[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",c);
    int len=strlen(c);
    for(int i=0;i<len;i++){
        if(c[i]>=48&&c[i]<=57){
            book[c[i]-48]++;
        }
    }
    for(int i=9;i>=0;i--){
        if(book[i]){
            for(int j=1;j<=book[i];j++){
                printf("%d",i);
            }
        }
    }
    return 0;
}