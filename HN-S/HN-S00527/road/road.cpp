#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int fa[100005];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
vector<pair<int,int> >g[100005];
int c[100005];
bool vis[100005];
struct note{
    int x,y,z,flag;
};
vector<note>b;
int a[15][100005];
bool cmp(note x,note y){
    return x.z<y.z;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        b.push_back(note{x,y,z,0});
        //g[x].push_back({y,z});
        //g[y].push_back({x,z});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
        for(int j=1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                b.push_back(note{j,p,a[i][j]+a[i][p],i});
            }
        }

    }
    int ans=k;
    sort(b.begin(),b.end(),cmp);
    for(int i=0;i<b.size();i++){
        if(find(b[i].x)!=find(b[i].y)){
            fa[find(b[i].x)]=find(b[i].y);
            ans+=b[i].z;
            if(b[i].flag!=0)vis[b[i].flag]=true;
            g[b[i].x].push_back({b[i].y,b[i].z});
            g[b[i].y].push_back({b[i].x,b[i].z});
        }
    }
    for(int i=1;i<=k;i++){
        if(!vis[i])ans--;
    }
    cout<<ans;
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
