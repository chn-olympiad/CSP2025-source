#include<bits/stdc++.h>
using namespace std;
#define maxm 1000005
#define maxn 10005
#define int long long

struct edge{
    int x,y,w;
    friend bool operator <(edge x,edge y){
        return x.w<y.w;
    }
};

int n,m,k,a[15][maxn],c[maxn],fa[maxn],ans=0;
edge e[maxm];
vector<edge> v;

int find(int x){
    if(x==fa[x]){
        return x;
    }
    int root=find(fa[x]);
    fa[x]=root;
    return root;
}

bool merge(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
        fa[fx]=fy;
    }
    return fx==fy;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){;
        cin>>e[i].x>>e[i].y>>e[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
        sort(a[i]+1,a[i]+n+1);
    }

    sort(e+1,e+n+1);
    for(int i=1;i<=m && v.size()<n;i++){
        if(merge(e[i].x,e[i].y)) continue;
        ans+=e[i].w;
        v.push_back({e[i].x,e[i].y,e[i].w});
    }

    cout<<ans;

    return 0;
}
/*
5 5 0
1 2 5
2 3 6
3 4 7
4 5 8
5 1 9
*/
