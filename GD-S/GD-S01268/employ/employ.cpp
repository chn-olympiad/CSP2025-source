#include <bits/stdc++.h>

using namespace std;

#define int long long

#define fileio(x,y) freopen(x,"r",stdin),freopen(y,"w",stdout);
#define tup tuple<int,int,int>
#define fir(x) (get<0>(x))
#define sec(x) (get<1>(x))
#define thr(x) (get<2>(x))
#define pii pair<int,int>
#define bit(x) bitset<x>
#define pb emplace_back
#define i12 __int128_t
#define mt make_tuple
#define ll long long
#define mp make_pair

const int   mod=998244353;
const int   maxn=510;

int frac[maxn],invf[maxn];
int b[maxn],cnt[maxn];
int a[maxn],c[maxn];
int n,m;

int power(int a,int b,int p) { int tar=1; for(; b; b>>=1,a=1ll*a*a%p) if(b&1) tar=1ll*tar*a%p; return tar; }
int C(int n,int m) { return (n<0||m<0||n<m? 0ll:frac[n]*invf[m]%mod*invf[n-m]%mod); }
int A(int n,int m) { return (n<0||m<0||n<m? 0ll:frac[n]*invf[n-m]%mod); }

void work()
{
    /* Code */
    cin>>n>>m; int tar=0,tot=0;
    string s; cin>>s;
    for(int i=0; i<n; i++) a[i+1]=s[i]-'0',tot+=a[i+1];
    for(int i=1; i<=n; i++) cin>>c[i],b[i]=i;
    if(m>tot) return (void)(cout<<0<<'\n');
    if(m==1) // special C
    {
        int cho=0; tar=1;
        for(int i=1; i<=n; i++) cnt[c[i]]++; cho=cnt[0];
        for(int i=1; i<=n; i++)
        {
            if(a[i])
            {
                // cerr<<"mul "<<i<<' '<<cho<<' '<<tar<<'\n';
                (tar*=cho)%=mod,cho--;
            }
            cho+=cnt[i];
        }
        (tar*=frac[n-tot])%=mod;
        // cerr<<n<<' '<<tot<<' '<<tar<<'\n';
        cout<<(frac[n]-tar+mod)%mod<<'\n';
        return;
    }
    do {
        int out=0;
        for(int i=1; i<=n; i++)
        {
            if(!a[i]) out++;
            else if(out>=c[b[i]]) out++;
        }
        tar+=(n-out>=m);
        if(n-out<m&&false)
        {
            for(int i=1; i<=n; i++) cout<<b[i]<<' ';
            cout<<'\n';
        }
    } while(next_permutation(b+1,b+n+1));
    cout<<tar<<'\n';
    return;
}

signed main()
{
    fileio("employ.in","employ.out");
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    frac[0]=1; for(int i=1; i<maxn; i++) frac[i]=frac[i-1]*i%mod;
    invf[maxn-1]=power(frac[maxn-1],mod-2,mod);
    for(int i=maxn-2; ~i; i--) invf[i]=invf[i+1]*(i+1)%mod;
    while(t--) work();
    return 0;
} // Cellinia Texas.
