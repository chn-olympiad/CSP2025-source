#include<bits/stdc++.h>
using namespace std;
char s[1000050];
int a[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    int l=strlen(s+1);
    int k=0;
    for(int i=1;i<=l;i++)
        if(s[i]>='0'&&s[i]<='9')
            a[++k]=s[i]-'0';
    sort(a+1,a+k+1);
    for(int i=k;i>=1;i--)
        printf("%d",a[i]);
    return 0;
}
