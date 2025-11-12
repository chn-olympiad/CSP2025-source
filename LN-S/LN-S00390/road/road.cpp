#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int vis[10010];
int vz=0;
int s[10010][10010];
int min1=2147483647;
void dfs(int x,int sum){
    if(x<=n){
        vz++;
    }
    if(vz==n){
        if(sum<min1){
            min1=sum;
        }
    }
    vis[x]=1;
    for(int i=1;i<=n+k;i++){
        if(vis[i]==0&&s[x][i]!=-1){
            dfs(i,sum+s[x][i]);
        }
    }
    vis[x]=0;
    if(x<=n){
        vz--;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++){
        for(int j=1;j<=n+k;j++){
            s[i][j]=-1;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        s[a][b]=c;
        s[b][a]=c;
    }
    for(int i=n+1;i<=n+k;i++){
        int y;
        cin>>y;
        for(int j=1;j<=n;j++){
            int y1;
            cin>>y1;
            s[i][j]=y1+y;
            s[j][i]=y1;
        }
    }
    dfs(1,0);
    cout<<min1;
    return 0;
}
