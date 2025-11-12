#include <bits/stdc++.h>
using namespace std;
struct edge{
    int u,v;
    int w;
};
vector <edge> g[10005];
int n,m,k;
int main(){
    freopen("road.in","r",stdout);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back((edge){a,b,c});
        g[b].push_back((edge){b,a,c});
    }
    int modify[15][2]={0};//new,road
    for(int i=1;i<=k;i++){
        scanf("%d",&modify[i][0]);
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&modify[i][1]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=g[i][1].w;
    }
    cout<<ans;
}
