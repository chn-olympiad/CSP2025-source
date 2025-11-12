#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define f(i,j,n) for(int i=j;i<=n;i++)
#define F(i,n,j) for(int i=n;i>=j;i--)
#define updmin(a,b) a=min(a,b)
#define updmax(a,b) a=max(a,b)
#define updsum(a,b) a=(a+(b))%mod
#define updtim(a,b) a=a*(b)%mod
using namespace std;
typedef pair<int,int> pii;
namespace fsd{
    const int MX=1<<20;
    char buf[MX],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,MX,stdin),p1==p2)?EOF:*p1++)
    inline int read(){
        int ak=0,csp=1;
        char c=gc();
        while(!isdigit(c)){if(c=='-')csp=-1;c=gc();}
        while(isdigit(c))ak=ak*10+c-'0',c=gc();
        return ak*csp;
    }
}
using namespace fsd;
const int N=1e5+10;
struct abc{
    int x[3],mx,gmx;
}t[N];
#define NXD
int n;
int ct[3];
void gs(){
    n=read();
    f(j,0,2)ct[j]=0;
    f(i,1,n)f(j,0,2)t[i].x[j]=read();
    f(i,1,n){
        int mx=0;
        f(j,1,2)if(t[i].x[j]>=t[i].x[mx])mx=j;
        t[i].gmx=LLONG_MAX/2;
        f(j,0,2)if(j!=mx)updmin(t[i].gmx,t[i].x[mx]-t[i].x[j]);
        t[i].mx=mx;
        // ct[mx]++,ans+=t[i].x[mx];
    }
    sort(t+1,t+1+n,[&](abc a,abc b){return a.gmx>b.gmx;});
    int ans=0;
    f(i,1,n){
        ct[t[i].mx]++,ans+=t[i].x[t[i].mx];
        if(ct[t[i].mx]>n/2)ans-=t[i].gmx;
    }
    printf("%lld\n",ans);
}
// #define DXN
signed main(){
#ifndef DXN
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
#endif
#ifdef NXD
    int t=read();while(t--)
#endif
    gs();
    return 0;
}