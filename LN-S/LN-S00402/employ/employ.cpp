#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int n,m,a[550];
string s;
namespace forcerun
{
    int chd[550],p[550];
    ll ans = 0;
    void solve()
    {
        for(int i = 1;i<=n;i++)p[i] = i;
        do
        {
            int crt = 0;
            for(int i = 1;i<=n;i++)chd[i]=a[p[i]];
            for(int i = 1;i<=n;i++)
                if(s[i]=='0')crt++;
                else if(crt>=chd[i])crt++;
            if(n-crt>=m)(ans+=1)%=mod;
        } while (next_permutation(p+1,p+1+n));
        cout<<ans<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s = " " + s;
    for(int i = 1;i<=n;i++)cin>>a[i];
    forcerun::solve();
    return 0;
} 