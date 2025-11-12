#include <iostream>
#include <bitset>
#include <algorithm>
#include <functional>
using namespace std;
constexpr int N=503,mod=998244353;
bool b[N];
int c[N],p[N],fac[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        char cc;
        cin>>cc;
        b[i]=cc-'0';
    }
    int first_1=n+1;
    for (int i=1;i<=n;i++)
    {
        if (b[i])
        {
            first_1=i;
            break;
        }
    }
    if (first_1==n+1)
    {
        cout<<0;
        return 0;
    }
    //cout<<first_1<<'\n';
    for (int i=1;i<=n;i++)
    {
        cin>>c[i];
        //cout<<"c:"<<c[i]<<' ';
    }
    /*
    if (m==1)
    {
        sort(c+1,c+1+n,greater<int>());
        cout<<m<<' ';
        fac[0]=fac[1]=1;
        for (int i=1;i<=n;i++)
        {
            fac[i]=1ll*fac[i-1]*i%mod;
            //cout<<fac[i]<<' ';
        }
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            if (c[i]<=first_1-1) break;
            (ans+=fac[n-1])%=mod;
        }
        cout<<ans;
        return 0;
    }
    */
    for (int i=1;i<=n;i++)
    {
        p[i]=i;
    }
    int cnt=0;
    do
    {
        int fail=0;
        int getted=0;
        for (int i=1;i<=n;i++)
        {
            //cout<<p[i]<<' ';
            if (!b[i])
            {
                //cout<<'('<<i<<"failed) ";
                fail++;
                continue;
            }
            if (c[p[i]]<=fail)
            {
                fail++;
                continue;
            }
            getted++;

            if (getted>=m)
            {
                break;
            }
        }
        //cout<<getted<<'\n';
        if (getted>=m)
        {
            cnt++;
        }
    } while (next_permutation(p+1,p+1+n));
    cout<<cnt%mod;
}
