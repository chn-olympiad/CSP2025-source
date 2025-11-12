#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long ans=1;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans*=i;
        ans%=mod;
    }
    cout<<ans%mod;
    return 0;
}
//多给点分吧。。。
//求求了orz