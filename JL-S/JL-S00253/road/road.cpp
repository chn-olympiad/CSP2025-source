#include<bits/stdc++.h>
using namespace std;
int used[1001],a[1001][1001],n,m,c,x,y;
vector<int>x1[1001];
int dfs(int m,int ceng){
    if(ceng==n){
        return 0;
    }
    int ans=1e9;
    for(int i=0;i<x1[m].size();i++){
        if(used[x1[m][i]])continue;
        if(a[m][x1[m][i]]==-0x3f3f3f)continue;
        used[x1[m][i]]=true;
        ans=min(ans,dfs(x1[m][i],ceng+1)+a[m][x1[m][i]]);
        used[x1[m][i]]=false;
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>c;
    memset(a,-0x3f,sizeof(a));
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x1[x].push_back(y);
        x1[y].push_back(x);
        cin>>a[x][y];
        cin>>a[y][x];
    }
    for(int i=0;i<n;i++){
        cout<<dfs(n,1)<<' ';
    }
    return 0;
}
