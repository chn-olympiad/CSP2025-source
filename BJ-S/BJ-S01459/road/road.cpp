#include <bits/stdc++.h>
using namespace std;
vector<int> g[100001];
//int g[20001][20001];
vector<int> f(100001);
int n,m,k;
int num=INT_MAX;
int cun[10001];
 int a,b,c;
void dfs(int x,int y,int ans){
    int awa=0;
    for(int i=1;i<=n+k;i++){
        if(f[i]==1){
            awa++;
        }
    }
    if(awa==n+k){
        num=min(ans,num);
        return ;
    }
    if(f[y]==1){
        return ;
    }
    f[x]=1;
    if(x<=0||y<=0||x>=n+k||y>=n+k||ans>num){
        num=min(ans,num);
        return;
    }
    else{

        if(x>n){
        ans=ans+cun[x];
        ans=ans+g[x][y];
        if(g[x][y]!=INT_MAX){
        for(int i=1;i<=n+k;i++){
            dfs(y,i,ans);
        }
        }
        else{
            return ;
        }
        }
        else{
           for(int i=1;i<=n+k;i++){
                dfs(y,i,ans);
           }
        }


    }

}
int main(){
   freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
 cin >>n>>m>>k;
for(int i=1;i<=n+k;i++){
    for(int j=1;j<=n+k;j++){
        g[i].push_back(INT_MAX);
    }
}
 for(int i=1;i<=m;i++){
    cin >>a>>b>>c;
    g[a][b]=c;
    g[b][a]=c;
 }
 for(int i=1;i<=k;i++){
    cin >>a;
    cun[i+m]=a;
    for(int j=1;j<=n;j++){
        cin >>b;
        g[i+m][j]=b;
        g[j][i+m]=b;
    }
 }
for(int i=1;i<=n+k;i++){
    for(int j=1;j<=n+k;j++){
        dfs(i,j,0);
    }
}
 cout <<num;
return 0;
}
