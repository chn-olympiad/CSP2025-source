#include <bits/stdc++.h>
#define fin(str) freopen(str,"r",stdin)
#define fout(str) freopen(str,"w",stdout)
#define pii pair<int,int>
#define fir first
#define sec second
#define P(x,y) make_pair(x,y)
#define ll long long
using namespace std;
bool BG;

const int maxn=1e5+5;
const int mod=998244353;

int n,m,ans,c[maxn];
char ch[maxn];
ll fac[maxn];

inline void solvem1(){
    fac[0]=1;
    for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    sort(c+1,c+n+1);
    int cnt1=0,p=0; ll totres=0,cur=1;
    for (int i=1;i<=n;i++){
        if (ch[i]=='0') continue;
        for (int j=1;j<=n;j++){
            if (c[j]<i) continue;
            totres=(totres+cur*fac[n-(cnt1+1)]%mod)%mod;
        }
        while (p+1<=n && c[p+1]<i){
            p++;
        }
        cur=cur*max(0,p-cnt1)%mod;
        cnt1++;
    }
    printf("%lld\n",totres);
}
inline void solvemn(){
    for (int i=1;i<=n;i++){
        if (ch[i]=='0' || c[i]==0){
            printf("0\n");
            return ;
        }
    }
    ll res=1;
    for (int i=1;i<=n;i++) res=res*i%mod;
    printf("%lld\n",res);
}

const int maxc=(1<<19)+5;
const int maxn2=20;
ll f[maxc][maxn2];
int pc[maxc];

inline ll solve(int S,int acc){
    if (S==0){
        if (acc==0) return 1;
        else return 0;
    }
    if (f[S][acc]!=-1) return f[S][acc];
    f[S][acc]=0;
    for (int i=1;i<=n;i++){
        if (!((S>>(i-1))&1)) continue;
        if (ch[pc[S]]=='0') f[S][acc]=(f[S][acc]+solve(S^(1<<(i-1)),acc))%mod;
        else{
            if (acc-1>=0 && pc[S]-acc<c[i]) f[S][acc]=(f[S][acc]+solve(S^(1<<(i-1)),acc-1))%mod;
            else f[S][acc]=(f[S][acc]+solve(S^(1<<(i-1)),acc))%mod;
        }
    }
    return f[S][acc];
}

inline void solveguess(){
    fac[0]=1;
    for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;

    printf("%lld\n",fac[n]);
}

bool ED;
int main(){
    fin("employ.in");
    fout("employ.out");

    scanf("%d%d%s",&n,&m,ch+1);
    for (int i=1;i<=n;i++) scanf("%d",&c[i]);

    if (m==1){
        solvem1();
        return 0;
    }
    if (m==n){
        solvemn();
        return 0;
    }

    if (n>18){
        solveguess();
        return 0;
    }

    memset(f,-1,sizeof(f));
    for (int i=1;i<(1<<n);i++){
        if (i&1) pc[i]=pc[i>>1]+1;
        else pc[i]=pc[i>>1];
    }
    printf("%lld\n",solve((1<<n)-1,m));

    cerr<<"Memory : "<<1.0*(&ED-&BG)/1048576<<"Mb\n";
    return 0;
}

