#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){return a>b;}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[1000001];
    fgets(s,1000001,stdin);
    int n=strlen(s);
    int t=0;
    int a[n+1];
    for(int i=0;i<=n;i++)
        if(s[i]>='0'&&s[i]<='9')
        {
            t++;
            a[t]=s[i]-48;
        }
    sort(a+1,a+t+1,cmp);
    for(int i=1;i<=t;i++)
        printf("%d",a[i]);
    fclose(stdin);fclose(stdout);
    return 0;
}
