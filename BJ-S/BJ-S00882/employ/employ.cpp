#include <bits/stdc++.h>
using namespace std;
long long n,m,c=998244353,p,cnt,a;
long long x(long long p)
{
    long long j=1;
    while(p)
    {
        j*=p;
        j%=c;
        p--;
    }
    return j;
}
string s;
bool flag;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            flag=true;
        }
        else
        {
            cnt++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>p;
    }
    if(cnt<m)
    {
        cout<<0;
        return 0;
    }
    if(flag)
    {
        cout<<0;
        return 0;
    }
    if(n!=m)
    {
        cout<<0;
        return 0;
    }
    cout<<x(n);
    return 0;
}
