#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=3e6+13;
const int N=1e4+16;
struct edge{
    int x,y,w;
}f[maxn];
int fa[N],dx[N];
int gfa(int a){
    if(fa[a]==a) return a;
    else return fa[a]=gfa(fa[a]);
}
priority_queue< pair <int,int> >q;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,summ=0,fy;
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
        dx[i]=1;
    }
    for(int i=1;i<=m;i++){
        cin>>f[i].x>>f[i].y>>f[i].w;
        q.push({0-f[i].w,i});
    }
    for(int i=1;i<=k;i++){
        cin>>fy;
        summ+=fy;
        for(int j=1;j<=n;j++){
            cin>>f[m+(i-1)*n+j].w;
            f[m+(i-1)*n+j].x=i+n;
            f[m+(i-1)*n+j].y=j;
            q.push({0-f[m+(i-1)*n+j].w,m+(i-1)*n+j});
        }
    }
    while(dx[1]<(n+k)){
        int e2=q.top().second;
        q.pop();
        int x1=f[e2].x,x2=f[e2].y,w1=f[e2].w;
        if(gfa(x1)==gfa(x2)) continue;
        else if(gfa(x1)<gfa(x2)){
            dx[fa[x1]]+=dx[fa[x2]];
            fa[gfa(x2)]=gfa(x1);

        }
        else{
            dx[fa[x2]]+=dx[fa[x1]];
            fa[gfa(x1)]=gfa(x2);

        }
        summ+=w1;
    }
    cout<<summ;
    return 0;
}
