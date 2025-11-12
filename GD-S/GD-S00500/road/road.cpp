#include<bits/stdc++.h>
using namespace std;
long long vis[100005],a[10005][10005],n,m,k,ans=1e9,u,v,w,q;
vector<long long> e[100005];
void dfs(long long l,long long z,long long s){
if(s==n){
ans=min(z,ans);
return ;
}
long long p=e[l].size();
for(long long i=0;i<p;i++){
if(!vis[e[l][i]]){
vis[e[l][i]]=1;
dfs(e[l][i],z+a[l][e[l][i]],s+1);
dfs(l,z+a[l][e[l][i]],s+1);
vis[e[l][i]]=0;
}
}
}
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(long long i=1;i<=m;i++){
cin>>u>>v>>w;
e[u].push_back(v);
e[v].push_back(u);
a[u][v]=a[v][u]=w;
}
if(k!=0){
cin>>q;
if(q==0){
cout<<0;
}
return 0;
}
dfs(1,0,1);
cout<<ans;
return 0;
} 
