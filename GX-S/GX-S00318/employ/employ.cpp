#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define qwq Ff472130
#define f(i,l,r) for (int i=l;i<=r;i++)
#define F(i,r,l) for (int i=r;i>=l;i--)
const int N=500+10;
const int inf=1e9+7;
const int mod=998244353;
inline void add(ll &x,ll y) {x+=(x+y>=mod)?(y-mod):y;}

inline void read(int &x) {
    x=0;
    char ch=getchar();
    while (ch<48) ch=getchar();
    while (ch>=48) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}

int n,m,tot;
char s[N];
int a[N],b[N],cnt[N];
ll dp[2][N][N],ans;

struct Node {int op,val,flag;}p[N];
inline bool cmp(Node a,Node b) {return (a.flag==b.flag)?((a.val==b.val)?(a.op>b.op):(a.val<b.val)):(a.flag>b.flag);}

int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    read(n);read(m);
    scanf("%s",s+1);
    f(i,1,n) {
        a[i]=a[i-1]+(s[i]=='0');
        p[++tot]={0,a[i-1],s[i]-'0'};
    }
    f(i,1,n) {
        read(b[i]);
        p[++tot]={1,b[i],1};
    }
    sort(p+1,p+1+tot,cmp);
    //f(i,1,tot) printf("%d %d\n",p[i].op,p[i].val);
    f(i,1,tot) cnt[i]=cnt[i-1]+(p[i].op==0);
    dp[0][0][0]=1;
    f(i,1,tot) {
        const int d=i&1;
        f(j,0,cnt[i]) f(k,0,cnt[i]) {
            if (p[i].op==0) {
                add(dp[d][j+1][k],dp[d^1][j][k]);
                int c1=i-1-cnt[i-1]*2+j;
                add(dp[d][j][k],1ll*c1*dp[d^1][j][k]%mod);
            }
            else {
                add(dp[d][j][k],dp[d^1][j][k]);
                add(dp[d][j][k+1],1ll*(j+1)*dp[d^1][j+1][k]%mod);
            }
        }
        memset(dp[d^1],0,sizeof(dp[d^1]));
    }
    f(i,m,n) add(ans,dp[tot&1][0][i]);
    printf("%lld\n",ans);
    return 0;
}
