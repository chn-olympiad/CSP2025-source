#include<bits/stdc++.h>
#define ll long long 
#define ep emplace
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-') f=-1;
    for(;'0'<=c&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
const int N=1e5+10,mod=998244353;
int n,a[N][5],b[N],p[N],sz[5];
void misaka(){
    rep(i,1,n){
        b[i]=p[i]=0;
        rep(j,1,3) a[i][j]=0;
    }
    rep(i,1,3) sz[i]=0;
    n=read();
    rep(i,1,n) p[i]=i;
    rep(i,1,n){
        b[i]=0;
        rep(j,1,3) a[i][j]=read(),b[i]=max(b[i],a[i][j]);
    }
    sort(p+1,p+n+1,[](int x,int y){return b[x]>b[y];});
    priority_queue<int> q[4];
    int ans=0;
    rep(i,1,n){
        int id=0,mx=0,x=p[i];
        rep(j,1,3)if(b[x]==a[x][j]) id=j;
        rep(j,1,3)if(j^id) mx=max(mx,a[x][j]);
        sz[id]++;
        ans+=a[x][id];
        q[id].ep(mx-a[x][id]);
    }
    rep(j,1,3)
        rep(i,1,sz[j]-n/2) 
            ans+=q[j].top(),q[j].pop();
    printf("%d\n",ans);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    rep(i,1,T) misaka();
    return 0;
}