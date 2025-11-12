#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define mod 998244353
ll n,m,p[N],rej,c[N],ans;
char s[N];
bool fg=1;
int main()
{   
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;
    cin>>s+1;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) if(s[i]=='0') fg=0;
    if(n<=10)
    {
        do
        {
            rej=0;
            for(int i=1;i<=n;i++)
            {
                if(rej>=c[p[i]])
                {
                    rej++;
                    continue;
                }
                if(s[i]=='0') rej++;
            }
            if(rej<=n-m) ans++;
        }while(next_permutation(p+1,p+1+n));
        cout<<ans;
        return 0;
    }
    if(fg)
    {
        ans=1;
        for(ll i=1;i<=n;i++) ans=ans*i%mod;
        cout<<ans;
        return 0;
    }
    do
    {
        rej=0;
        for(int i=1;i<=n;i++)
        {
            if(rej>=c[p[i]])
            {
                rej++;
                continue;
            }
            if(s[i]=='0') rej++;
        }
        if(rej<=n-m) ans++;
    }while(next_permutation(p+1,p+1+n));
    cout<<ans;
    return 0;
}