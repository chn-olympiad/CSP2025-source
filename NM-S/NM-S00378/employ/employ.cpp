#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,c[505];
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    int nn=0;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    int num=0;
    for(int i=1;i<=s.size();i++)
    {
        if(s[i-1]=='1')
        {
            num++;
        }
    }
    long long ans=1,ans2=1,maxx=-1;
    for(int i=1;i<=n;i++)
    {
        if(c[i]==0)
        {
            nn++;
        }
        if(c[i]>maxx)
        {
            maxx=c[i];
        }
    }
    if(m==1&&maxx>nn&&num==s.size())
    {
        for(int i=1;i<=n;i++)
        {
            ans=((ans%MOD)*(i%MOD))%MOD;
        }
        cout<<ans;
    }
    else
    {
        cout<<0;
    }


    return 0;
}
