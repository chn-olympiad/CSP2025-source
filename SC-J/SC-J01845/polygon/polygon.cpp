#include<bits/stdc++.h>
#define int long long
using namespace std;

ifstream fin("polygon.in");
ofstream fout("polygon.out");
static constexpr const int Mod=998244353;
int n,a[5001],f[5005],ans;

signed main()
{
    // freopen("polygon.in","r",stdin);
    // freopen("polygon.out","w",stdout);
    fin>>n;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    sort(a+1,a+n+1);
    int Max=a[n];
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=Max+1;j>a[i];j--)
            (ans+=f[j])%=Mod;
        for(int j=Max+1;j+a[i]>Max;j--)
            (f[Max+1]+=f[j])%=Mod;
        for(int j=Max;j>=a[i];j--)
            (f[j]+=f[j-a[i]])%=Mod;
    }
    fout<<ans<<"\n";
}