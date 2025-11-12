#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl "\n"
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define TIMESTAMP cerr<<fixed<<setprecision(3)<<(double)clock()/CLOCKS_PER_SEC<<"s"<<endl;
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define _iter(it,a) for (auto it=a.begin();it!=a.end();++it)
#define i32 signed
#define u32 unsigned
#define i64 long long
#define u64 unsigned long long
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

const int N=505;
const int mod=998244353;

int n,m;
char s[N];
int c[N];
int p[N];
int f[2][20][270000];
vector<int> vec[20];

int popc(int k) {
    int ans=0;
    while (k) ans+=(k&1),k>>=1;
    return ans;
}

void init() {
    _rep(i,0,(1<<n)-1) vec[popc(i)].emplace_back(i);
}

i32 main() {
    FRR("employ.in");
    FRW("employ.out");
    scanf("%lld %lld",&n,&m);
    scanf("%s",s+1);
    _rep(i,1,n) scanf("%lld",&c[i]);
    if (n<=10) { // 1-2
        _rep(i,1,n) p[i]=i;
        int ans=0;
        do {
            int sum=0,cur=0;
            _rep(i,1,n) {
                if (s[i]=='1' && cur<c[p[i]]) sum++;
                else cur++;
            }
            if (sum>=m) ans++;
        } while (next_permutation(p+1,p+1+n));
        printf("%lld",ans);
        return 0;
    } else if (n<=18) { // 3-5
        init();
        f[0][0][0]=1;
        _rep(i,1,n) {
            memset(f[i&1],0,sizeof(f[i&1]));
            _rep(j,0,i) _iter(it,vec[i]) {
                int k=(*it);
                _rep(p,1,n) if ((k>>(p-1))&1) {
                    int g=(k^(1<<(p-1)));
                    if (j && (j-1>=c[p] || s[i]=='0')) f[i&1][j][k]=(f[i&1][j][k]+f[(i&1)^1][j-1][g])%mod;
                    if (s[i]=='1' && j<c[p]) f[i&1][j][k]=(f[i&1][j][k]+f[(i&1)^1][j][g])%mod;
                }
            }
        }
        int ans=0;
        _rep(i,0,n-m) ans=(ans+f[n&1][i][(1<<n)-1])%mod;
        printf("%lld",ans);
        return 0;
    }
    return 0;
}