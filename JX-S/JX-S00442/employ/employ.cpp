#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int c[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    char s[505];
    cin>>n>>m;
    cin>>s;
    bool f=1;
    for(int i=0;i<strlen(s);i++) if(s[i]!='1')
    {
        f=0;
        break;
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    if(f)
    {
        long long ans=1;
        for(int i=1;i<=n;i++) ans*=i,ans%=mod;
        cout<<ans;
        return 0;
    }
    return 0;
}
