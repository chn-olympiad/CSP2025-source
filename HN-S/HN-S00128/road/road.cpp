#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+55,M=1e6+5;
int fa[N];
int findfa(int x){
    return (fa[x]==0?x:(fa[x]=findfa(fa[x])));
}
void merge(int x,int y){
    if(findfa(x)!=findfa(y))
    fa[findfa(x)]=findfa(y);
}
int n,m,k;
int c[15];
struct edge{
    int u,v,w;
    bool operator<(const edge&_1)const{
        return w<_1.w;
    }
}e[M],e2[12][N];
struct S1{
    edge w;int id;
    bool operator<(const S1&_1)const{
        return _1.w<w;
    }
};
priority_queue<S1> q;
int cnt=0;
int ans=0;
int a[15],b[15];
int idx[15];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++) cin>>u>>v>>w,e[i]={u,v,w};
    sort(e+1,e+m+1);
    for(int i=1;i<=k;i++) {
        cin>>c[i];
        for(int j=1,x;j<=n;j++) cin>>x,e2[i][j]={n+i,j,x};
        sort(e2[i]+1,e2[i]+n+1);
    }
    q.push({e[1],0});
    idx[0]=1;
    for(int i=1;i<=k;i++){
        edge tmp=e2[i][1];
        tmp.w+=(a[i]=c[i]);
        q.push({tmp,i});
        idx[i]=1;
    }
    int nn=n-1;
    while(cnt<nn){
        S1 now=q.top();q.pop();
        if(findfa(now.w.u)!=findfa(now.w.v)){
        //cout<<now.id<<' '<<now.w.u<<' '<<now.w.v<<' '<<now.w.w<<'\n';
            merge(now.w.v,now.w.u);
            ans+=now.w.w;
            cnt++;
            if(now.id!=0){
                if(b[now.id]==0)
                    nn++,a[now.id]=now.w.w,b[now.id]=2,c[now.id]=now.w.w;
                else if(b[now.id]==2) b[now.id]=1,a[now.id]=0;

            }

        }
        if(now.id==0){if((++idx[0])<=m) q.push({e[idx[0]],0});}
        else if((++idx[now.id])<=n) {
            edge tmp=e2[now.id][idx[now.id]];
            tmp.w+=a[now.id];
            //cout<<now.id<<' '<<tmp.u<<' '<<tmp.v<<' '<<tmp.w<<'\n';
            q.push({tmp,now.id});
        }
    }
    for(int i=1;i<=k;i++){
        if(b[i]!=0) ans-=c[i];
    }
    cout<<ans;
    return 0;
}
