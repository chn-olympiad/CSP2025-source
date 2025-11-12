#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u=0,v=0,w=0;
    bool operator>(const edge& x)const{
        return w>x.w;
    }
};

int n,m,k;
long long ans=LLONG_MAX;
int c[11];
int fa[10020],siz[10020];
int a[11][10010];
priority_queue<edge,vector<edge>,greater<edge> > g;
priority_queue<edge,vector<edge>,greater<edge> > pq;

int fnd(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=fnd(fa[x]);
}

void mge(int x,int y){
    int fx=fnd(x),fy=fnd(y);
    if(siz[fx]<siz[fy]){
        swap(fx,fy);
    }
    fa[fy]=fx;
    siz[fx]+=siz[fy];
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    edge nowp;
    for(int i=1;i<=m;i++){
        cin>>nowp.u>>nowp.v>>nowp.w;
        g.push(nowp);
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<(int)pow(2,k);i++){
        pq=g;
        int t=i,now=1,tsiz=1,cnt=0;
        long long nans=0;
        for(int j=1;j<=n+k;j++){
            fa[j]=j;
            siz[j]=1;
        }
        while(t){
            if(t&1){
                nans+=c[now];
                cnt++;
                for(int j=1;j<=n;j++){
                    pq.push({n+now,j,a[now][j]});
                }
            }
            t>>=1;
            now++;
        }
        while(!pq.empty()&&tsiz<n+cnt){
            edge tp=pq.top();
            pq.pop();
            int u=tp.u,v=tp.v,w=tp.w;
            if(fnd(u)==fnd(v)){
                continue;
            }
            mge(u,v);
            nans+=w;
            tsiz++;
        }
        ans=min(ans,nans);
    }
    cout<<ans<<'\n';

    return 0;
}
