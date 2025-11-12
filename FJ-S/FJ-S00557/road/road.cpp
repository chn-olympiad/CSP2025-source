#include<bits/stdc++.h>
using namespace std;
vector<int>q[10005];
int x,y,p[10005],f[10005],c[15],a[15][10005],ans=1e9,n,m,k,u,v,w,cnt=0;
struct s{
int u,v,w,p;
}e[1000005];
int fi(int t){
if(f[t]==0)return t;
return f[t]=fi(f[t]);
}
bool h(){
for(int i=1;i<=n;i++){
for(int j=1;j<=p[i];j++){
x=fi(i);
y=fi(q[i][j]);
if(x!=y)f[x]=y;
}
}
for(int i=1;i<n;i++){
for(int j=i+1;j<=n;j++){
x=fi(i);
y=fi(j);
if(x!=y)return 0;
}
}
return 1;
}
void dfs(int t,int sum){
if(sum>=ans){
return;
}
if(t>cnt)return;
if(t>=n-1){
if(h()){
ans=min(ans,sum);
return;
}
}
for(int i=t;i<=cnt;i++){
q[e[i].u].push_back(e[i].v);
p[e[i].u]++;
q[e[i].v].push_back(e[i].u);
p[e[i].v]++;
dfs(i+1,sum+e[i].w);
q[e[i].u].pop_back();
p[e[i].u]--;
q[e[i].v].pop_back();
p[e[i].v]--;
}
}
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
cin>>e[++cnt].u>>e[cnt].v>>e[cnt].w;
}
for(int i=1;i<=k;i++){
cin>>c[i];
for(int j=1;j<=n;j++){
cin>>a[i][j];
}
}
dfs(1,0);
cout<<ans;
return 0;
}
