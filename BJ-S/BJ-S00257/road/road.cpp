#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int mp[1005][1005];
int uv[1000006][2];
int a[10][1005];
int ans=1e9;
void dfs(int id,int cnt){
    if(cnt>=ans){
        return ;
    }
    if(id>m){
        ans=min(ans,cnt);
        return ;
    }
    int k=mp[uv[id][0]][uv[id][1]];
    dfs(id+1,cnt+k);
    for(int i=1;i<=k;i++){
        k=a[i][uv[id][0]]+a[i][uv[id][1]]+a[i][0];
        int ai1,ai2,ai3;
        ai1=a[i][uv[id][0]];
        ai2=a[i][uv[id][1]];
        ai3=a[i][0];

        a[i][uv[id][0]]=0;
        a[i][uv[id][1]]=0;
        a[i][0]=0;

        dfs(id+1,cnt+k);

        a[i][uv[id][0]]=ai1;
        a[i][uv[id][1]]=ai2;
        a[i][0]=ai3;
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mp[u][v]=w;
        uv[i][0]=u;
        uv[i][1]=v;
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin>>a[i][j];
        }
    }
    dfs(1,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
