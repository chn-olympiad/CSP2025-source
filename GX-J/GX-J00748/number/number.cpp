#include<bits/stdc++.h>
using namespace std;
char a[1000001],b[1000001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",a+1);
    int len=strlen(a+1);
    int m=0;
    for(int i=1;i<=len;i++){
        if(a[i]>='0'&&a[i]<='9')
            b[++m]=a[i];
    }
    sort(b+1,b+m+1);
    for(int i=m;i>=1;i--)
        printf("%c",b[i]);
    return 0;
}
