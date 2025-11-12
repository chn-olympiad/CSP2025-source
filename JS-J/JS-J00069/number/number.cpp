#include <bits/stdc++.h>
using namespace std;
string s;
long long cspa[1000005]={};
long long cnt=0;

bool cmp(long long cspx,long long cspy)
{
    return cspx>cspy;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            cspa[i]=s[i]-'0';
            cnt++;
        }
    }
    sort(cspa,cspa+s.length()+1,cmp);
    if(cspa[0]==0)
    {
        printf("%c",'0');
    }
    else
    {
        for(int i=0;i<cnt;i++)
        {
            printf("%lld",cspa[i]);
        }
    }
    return 0;
}
