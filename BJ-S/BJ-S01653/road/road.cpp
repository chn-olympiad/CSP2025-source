#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int r[10010][10010],v[15][10010],minn=1e9;
bool vis[10010];
void dfs(int p,int s,int visn){
    if(visn==n){
        minn=min(minn,s);
        return;
    }
    vis[p]=1;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        dfs(i,s+r[p][i],visn+1);
        vis[i]=0;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(r[a][b]==0)r[a][b]=c;
        else r[a][b]=min(r[a][b],c);
        r[b][a]=r[a][b];
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin>>v[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(r[i][j]==0)r[i][j]=1e9;
            for(int a=1;a<=k;a++){
                int s=v[a][i]+v[a][j]+v[a][0];
                r[i][j]=min(r[i][j],s);
                r[i][j]=r[i][j];
            }
        }
    }
    //cout<<r[1][3]+r[3][4]+r[4][2];
    dfs(1,0,1);
    cout<<minn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
