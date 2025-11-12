#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define endll " "
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define lowbit(x) x&-x
#define it inline int
#define iv inline void
#define ib inline bool
using namespace std;
const int MAXN=500050;
const int INF=0x3f3f3f3f3f3f3f3f;
const int MOD=998244353;
it gcd(int x,int y) {return y==0?x:gcd(y,x%y);}
it lcm(int x,int y) {return x/gcd(x,y)*y;}
it max(int x,int y) {return x>y?x:y;}
it min(int x,int y) {return x<y?x:y;}
it ksm(int x,int m,int mod)
{
    int res=1,bas=x%mod;
    while(m)
    {
        if(m&1)
            res=(res*bas)%mod;
        bas=(bas*bas)%mod;
        m >>= 1;
    }
    return res;
}
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
int n,m,l,r,u,v,w,cnt,tot,ans,head[MAXN];
signed main()
{
    fre("replace");
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    while(m--)
        cout<<0<<endl;
    return 0;
}
