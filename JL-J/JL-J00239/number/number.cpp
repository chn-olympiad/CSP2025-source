#include<bits/stdc++.h>
using namespace std;
char ch[2200000];
int t[1100];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i,a,n;
    scanf("%s",ch);
    n=strlen(ch);
    for(i=0;i<n;i++)
    {
        if(ch[i]>='0'&&ch[i]<='9')
        {
            a=(ch[i]-'0');
            t[a]++;
        }
    }
    for(i=9;i>=0;i--)
    {
        while(t[i]>0)
        {
            printf("%d",i);
            t[i]--;
        }
    }
    return 0;
}
