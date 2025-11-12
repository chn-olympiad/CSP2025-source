#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
using namespace std;
int n,m;
const int N=510,mod=998244353;
string s;
int cs[N],fac[N],inv[N],c[N];
void init(int n)
{
    fac[0]=inv[0]=inv[1]=1;
    for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
    for(int i=2;i<=n;i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    for(int i=1;i<=n;i++) inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
inline int C(int a,int b)
{
    if(a>b) return 0;
    return 1ll*fac[b]*inv[a]%mod*inv[b-a]%mod;
}
int f[1<<18][19];
inline void add(int &x,int y)
{
    x+=y;
    if(x>=mod) x-=mod;
}
void solve1()
{
    f[0][0]=1;
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>>j&1) continue;
            for(int p=0;p<=__builtin_popcount(i);p++)
            {
                if(!f[i][p]) continue;
                if(p>=c[j+1]||s[__builtin_popcount(i)+1]=='0') add(f[i|(1<<j)][p+1],f[i][p]);
                else add(f[i|(1<<j)][p],f[i][p]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n-m;i++) add(ans,f[(1<<n)-1][i]);
    cout<<ans;
}
vector<int> op;
int ct[20],k;
int calc(int S)
{
    int anss=fac[n-__builtin_popcount(S)];
    for(int i=k-1;i>=0;i--) 
    {
        ct[i]=ct[i+1];
        if(S>>i&1) ct[i]++;
    }
    int cnt=0;
    for(int i=0;i<k;i++)
    {
        if(!(S>>i&1)) continue;
        if((cs[op[i]-cnt]-ct[i]+1)<=0) return 0;
        anss=1ll*anss*(cs[op[i]-cnt]-ct[i]+1)%mod;
        cnt++;
    }
    return anss;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    s='0'+s;
    init(n);
    for(int i=1;i<=n;i++) cin>>c[i],cs[c[i]]++;
    if(n<=18) solve1();
    return 0;
}