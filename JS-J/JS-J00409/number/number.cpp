#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int a[1000001],lena;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    int k=strlen(s+1);
    for(int i=1;i<=k;i++){
        if(s[i]>='0' and s[i]<='9'){
            lena++;
            a[lena]=s[i]-'0';
        }
    }
    sort(a+1,a+lena+1);
    for(int i=lena;i>=1;i--){
        printf("%d",a[i]);
    }
    return 0;
}
