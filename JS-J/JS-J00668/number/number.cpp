#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
char s[1000010];
int a[1000010];
int main()
{
    freopen("number.in", "r",stdin);
    freopen("number.out", "w",stdout);
    scanf("%s",s);
    int n=strlen(s);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[cnt]=s[i]-'0';
            cnt++;
        }
    }
    if(cnt==0)
    {
        cout<<0;
        return 0;
    }
    sort(a,a+cnt,cmp);
    if(a[0]==0)
    {
        cout<<0;
    }else
    {
        for(int i=0;i<cnt;i++)
        {
            cout<<a[i];
        }
    }
    return 0;
}
