#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
    int v,w;
};
vector<node> mp[10005];
int c[15],a[15][10005];
bool vis[100005];
long long ans=100000000000000;
void dfs(int x,long long y,int z){
    if(z==n){
        ans=min(ans,y);
        return ;
    }
    for(node i:mp[x]){
        if(!vis[i.v]){
            vis[x]=1;
            dfs(i.v,y+i.w,z+1);
            vis[x]=0;
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int x,y,z;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        mp[x].push_back({y,z});
        mp[y].push_back({x,z});
    }

    for(int i=1;i<=k;i++){
        bool flag=1;
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]!=0){
                flag=0;
            }
        }
        if(flag&&c[i]==0){
            cout<<0;
            return 0;
        }
    }
    vis[1]=1;
    dfs(1,0,1);
    cout<<ans-n;
    return 0;
}
