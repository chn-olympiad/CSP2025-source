#include<bits/stdc++.h>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define int long long
using namespace std;
struct Edge{
    int x,y,zval;
};
bool operator < (Edge aa,Edge bb){
    return aa.zval>bb.zval;
}
Edge e[2000006];
int n,m,k,fa[200005],c[11],a[11][20004],d[11],cnt=LONG_LONG_MAX;
int get(int x){
    if(fa[x]==x)return x;
    else{
        fa[x]=get(fa[x]);
        return fa[x];
    }
}
void krus(){
    int ans=0,l=0;
    priority_queue <Edge> q;
    rep(i,1,n+k){
        fa[i]=i;
    }
    rep(i,1,m){
        q.push(e[i]);
    }
    rep(i,1,k){
        if(d[i]){
            l++;
            ans+=c[i];
            rep(j,1,n){
                q.push((Edge){i+n,j,a[i][j]});
            }
        }
    }
    for(int j=0;j<n+l-1;){
        Edge E=q.top();
        int xx=E.x,yy=E.y;
        xx=get(xx);yy=get(yy);
        if(xx!=yy){
            fa[xx]=yy;
            j++;
            ans+=E.zval;
        }
        q.pop();
    }
    cnt=min(cnt,ans);
}
void dfs(int x){
    if(x>k){
        krus();
        return;
    }
    dfs(x+1);
    if(c[x]>cnt)return;
    d[x]=1;
    dfs(x+1);
    d[x]=0;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    rep(i,1,m){
        int xx,yy,zz;
        scanf("%lld%lld%lld",&xx,&yy,&zz);
        e[i].x=xx;
        e[i].y=yy;
        e[i].zval=zz;
    }
    rep(i,1,k){
        scanf("%lld",&c[i]);
        rep(j,1,n){
            scanf("%lld",&a[i][j]);
        }
    }
    dfs(1);
    printf("%lld",cnt);
    return 0;
}
