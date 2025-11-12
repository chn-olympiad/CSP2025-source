#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
const int N=5e2;
int c[N];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    string s;
    cin>>n>>m>>s;
    int len=s.size();
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    bool flagA=true;
    for(int i=0;i<len;i++)
    {
        if(s[i]==0) flagA=false;
    }
    if(flagA)
    {
        long long ans=1;
        for(long long i=n;i>n-m;i--)
        {
            ans=ans*i%mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
