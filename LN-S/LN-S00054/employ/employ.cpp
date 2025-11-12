#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
const long long mod=998244353;
long long n,m;
string s;
long long a[N];
long long f=0;
long long ans=1;
int main()
{   
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(long long i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            f=1;
            break;
        }
    }
   // cout<<f<<" ";
    if(f==0)
    {
        for(long long i=1;i<=n;i++)
            ans*=i,ans%=mod;
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}