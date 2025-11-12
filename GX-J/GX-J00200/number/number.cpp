#include <bits/stdc++.h>
using namespace std;

char s[110000];
int a[110000];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    int l=strlen(s+1);
    int x=1;
    for(int i=1;i<=l;i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            a[x]=s[i]-'0';
            x++;
        }
    }
    for(int i=1;i<=x;i++){
        for(int j=i;j<=x;j++){
            if(a[i]<a[j]){
                int m=a[i];
                a[i]=a[j];
                a[j]=m;
            }
        }
    }
    for(int i=1;i<=x-1;i++){
        printf("%d",a[i]);
    }
    return 0;
}
