#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>g[10001];
struct edge{
    int u,v,w;
}a[1000001];
int k;
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        a[i].u=u;
        a[i].v=v;
        a[i].w=w;
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
        ans=ans+w;
    }
    int tmp1=1e9;
    for(int i=1;i<=k;++i){
        int h=0;
        for(int j=1;j<=n;++j){
            int tmp;
            cin>>tmp;
            h+=tmp;
        }
        tmp1=min(tmp1,h);
    }
    cout<<min(tmp1,ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
