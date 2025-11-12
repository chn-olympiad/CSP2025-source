#include<bits/stdc++.h>

using namespace std;
vector<pair<int,int> >v[1000025];
queue<int>q;
int n,m,k;
struct E{
    int u,v,w;
}e[1000005];
int cnt=0;
int fa[10005];
bool cmp(E x,E y){
    return x.w<y.w;
}
long long ans=0;
void kr(){
    sort(e+1,e+1+cnt,cmp);
    //cnt=unique(e+1,e+1+cnt,cmp)-e;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<n;i++){
        //cout<<e[i].w<<" ";
        if(fa[e[i].u]!=fa[e[i].v]){
            fa[e[i].v]=min(fa[e[i].u],fa[e[i].v]);
            fa[e[i].u]=min(fa[e[i].u],fa[e[i].v]);
            ans+=e[i].w;
        }else{
            n++;
        }

    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
        //e[++cnt]={x,y,z};
        e[++cnt]={y,x,z};
    }
    for(int i=1;i<=k;i++){
        int c;
        cin>>c;
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            v[n+i].push_back({j,c+x});
            v[j].push_back({n+i,c+x});
            //e[++cnt]={n+i,j,c+x};
            e[++cnt]={j,n+i,c+x};
        }
    }
    n=n+k;
    kr();
    cout<<ans;
    return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

4 4 0
1 2 3
1 3 1
3 4 5
2 3 2
*/
