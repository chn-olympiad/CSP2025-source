#include <bits/stdc++.h>
using namespace std;
char s[1000000];
int a[1000000];
long long xb;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",&s);
    long long b=strlen(s);
    for(long long i=0;i<b;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[xb++]=s[i]-'0';
        }
    }
    sort(a,a+xb);
    for(int i=xb-1;i>=0;i--){
        printf("%d",a[i]);
    }
}
