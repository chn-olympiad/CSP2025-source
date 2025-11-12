#include<bits/stdc++.h>
int m,n,k;
int maps[20000][20000];
int res=INT_MAX;
int cres=0;
bool vis[1000000];
using namespace std;
int dfs(int p,int level=1)
{
    if(level==n){
        res=min(res,cres);
    }
    int adds=0;
    for(int i=1;i<=n;i++)
    {
        bool used[100000];
        for(int i=1;i<=10000;i++)
            used[i]=0;
        for(int j=i,pp=0;j<=n;j++)
        {
        if(maps[p][j]!=0&&vis[j]==0)
        {
            pp++;
            vis[j]=1;
            used[j]=1;
            cres+=maps[p][j];
            dfs(i,level+pp);
        }
        }
        for(int j=1;j<=n;j++){
            if(used[j]==1){
            vis[j]=0;
            cres-=maps[p][j];
            }
        }
    }
}
int main()
{

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        cin>>maps[a][b];
        maps[b][a]=maps[a][b];
    }
    dfs(1);
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
