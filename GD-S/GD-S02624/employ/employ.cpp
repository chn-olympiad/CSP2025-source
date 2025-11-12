#include <bits/stdc++.h>
#define For(e,e1,e2) for(int e=(e1);e<=(e2);e++)
#define For_(e,e1,e2) for(int e=(e1);e<(e2);e++)
#define Rof(e,e1,e2) for(int e=(e2);e>=(e1);e--)
#define Rof_(e,e1,e2) for(int e=(e2);e>(e1);e--)
#define LL long long
#define ULL unsigned long long
#define DB double
#define cint const int
#define cLL const long long
#define vct vector
#define pb push_back
#define sz(ev) ((int)ev.size())
#define all(ev) ev.begin(),ev.end()
#define ft first
#define sc second
#define exc(e) if(e) continue
#define stop(e) if(e) break
#define ret(e) if(e) return 
using namespace std;

void main_init()
{

}
cLL mod=998244353ll;
void Add(LL &w1,LL w2)
{
    w1=(w1+w2)%mod;
    if(w1<0ll) w1+=mod;
}
cint N=510;
int n,m;
char str[N]; int s0[N];
LL d1[N],C[N][N];
int c[N];
LL f[N][N][N];
void main_solve()
{
    scanf("%d%d%s",&n,&m,str+1);
    s0[0]=0; For(i,1,n) s0[i]=s0[i-1]+(str[i]=='0');
    d1[0]=1ll; For(i,1,n) d1[i]=d1[i-1]*i%mod;
    For(i,1,n)
    {
        int t; scanf("%d",&t);
        int k=1; while(k<=n&&t>s0[k-1]) k++;
        c[k]++;
    }
    // printf("c: "); For(i,1,n+1) printf("%d ",c[i]); printf("\n");
    f[0][0][0]=1ll;
    For_(i,0,n) For(j,0,n) For(k,0,i) if(f[i][j][k])
    {
        int j2=j+c[i+1];
        if(str[i+1]=='1')
        {
            if(j2) Add(f[i+1][j2-1][k],f[i][j][k]*j2);
            if(j2) Add(f[i+1][j2-1][k+1],-f[i][j][k]*j2);
            Add(f[i+1][j2][k+1],f[i][j][k]);
        }
        else
            Add(f[i+1][j2][k],f[i][j][k]);
    }
    LL ans=0ll;
    For(j,0,n) For(k,m,n) if(f[n][j][k])
    {
        // printf("j=%d,k=%d:%lld\n",j,k,f[n][j][k]);
        Add(ans,f[n][j][k]*d1[j+c[n+1]]);
    }
    ans%=mod; if(ans<0ll) ans+=mod;
    printf("%lld\n",ans);
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    main_init();
    // int _; scanf("%d",&_); while(_--)
        main_solve();
    return 0;
}