#include<bits/stdc++.h>
using namespace std;
char s[1000000];
int a[1000000];
int n,m;
int main()
{
    freopen("number,in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s);
    n=strlen(s+1); 
    for(int i=1;i<=n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')  
        {
             a[++m]=s[i]-'0';
        } 
    sort(a+1,a+m+1);
    for(int i=m;i>=1;i--)
    {
         if(in=f[i][j])
             printf("%d %d %d",j,i)  
             return 0;
    }
    return 0;
}
