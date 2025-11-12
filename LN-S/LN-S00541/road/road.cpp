#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=1e9;
struct node{
    int u,v,x;
};
vector<node>g;
int fa[100005];
bool cmp(node x,node y){
    return x.x<y.x;
}
int v[15];
int solve(int x);
void dfs(int x,int s){
    if(x>k){
        ans=min(ans,solve(s));
        if(ans==0){
            cout<<ans<<endl;
            exit(0);
        }
        return;
    }
    dfs(x+1,s);
    v[++s]=x;
    dfs(x+1,s);
}
int a[15][1005][1005];
int find(int x){
    if(fa[x]!=x){
        return fa[x]=find(fa[x]);
    }
    return x;
}
node ac[1000005];
int c[15];
int solve(int x){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    int ans=0;
    for(int i=1;i<=x;i++){
        ans+=c[v[i]];
        for(int j=1;j<=n;j++){
            for(int jj=j+1;jj<=n;jj++){
                g.push_back({j,jj,a[v[i]][j][jj]});
            }
        }

    }
    sort(g.begin(),g.end(),cmp);
    for(int i=0;i<n-1;i++){
        int x=g[i].x;
        int u=g[i].u;
        int v=g[i].v;
        if(find(u)!=find(v)){
            ans+=x;
            fa[u]=v;
        }
    }
    g.clear();
    for(int i=1;i<=m;i++){
        g.push_back({ac[i].u,ac[i].v,ac[i].x});
    }
    return ans;
}



int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&ac[i].u,&ac[i].v,&ac[i].x);
        g.push_back({ac[i].u,ac[i].v,ac[i].x});
    }

    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j][j]);
        }
        for(int j=1;j<=n;j++){
            for(int jj=j+1;jj<=n;jj++){
                if(j==jj){
                    continue;
                }
                a[i][j][jj]=a[i][j][j]+a[i][jj][jj];
            }
        }
        for(int j=1;j<=n;j++){
            a[i][j][j]=0;
        }
    }
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}
