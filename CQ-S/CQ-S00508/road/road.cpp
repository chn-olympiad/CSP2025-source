#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
#define N 10005
struct edge{
    int u,v,w;
}e[5000005],tr[N<<3],tmp[N<<3];int tote;
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int c[15][N<<2];

int fa[N<<2];
void clear(int n){
    for(int i=1;i<=n;i++)fa[i]=i;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(x!=y)fa[x]=y;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        e[++tote]={u,v,w};
    }
    sort(e+1,e+m+1,cmp);
    for(int i=1,u,w;i<=k;i++){
        cin>>c[i][0];
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    int cnt=0;
    clear(n);
    for(int i=1;i<=tote;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        if(cnt>=n-1)break;
        if(find(u)==find(v))continue;
        merge(u,v);
        // cout<<u<<" "<<v<<" "<<w<<endl;
        tr[++cnt]={u,v,w};
    }
    int S=(1<<k),res=LLONG_MAX;
    for(int s=0;s<S;s++){
        for(int i=1;i<=n+k-1;i++)tmp[i]=tr[i];
        int cntt=cnt,addn=0;
        int ans=0;
        for(int i=1;i<=k;i++){
            if(!(s&(1<<(i-1))))continue;
            ans+=c[i][0];
            addn++;
            for(int j=1;j<=n;j++){
                tmp[++cntt]={n+i,j,c[i][j]};
            }
        }
        sort(tmp+1,tmp+cntt+1,cmp);
        clear(n+addn);
        int tott=0;
        for(int i=1;i<=cntt;i++){
            int u=tmp[i].u,v=tmp[i].v,w=tmp[i].w;
            if(tott>=n+addn-1)break;
            if(find(u)==find(v))continue;
            // cout<<s<<" tree: "<<u<<" "<<v<<" "<<w<<endl;
            merge(u,v);
            tott++;
            ans+=w;
        }
        res=min(res,ans);
    }
    cout<<res;
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/