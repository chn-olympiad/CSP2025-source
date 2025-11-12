#include<bits/stdc++.h>
using namespace std;
struct bri{
	int u,v,w;
}a[1000005];
int n,m,k,ma[10005][10005],inf=100000001,minn,s,minnn=100000001,flag,ji1,ji2;
bool c[10001];
void dfs(int x){
//	if(ji1==n-1)
	for(int i=1;i<=n;i++){
		if(x!=i){
		if(ma[x][i]!=inf) continue;
		if(!c[i]) continue;
		minnn=min(s,minnn);
	}}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(ma[i][x]==inf) continue;
		else{ 
			int l=ma[i][x];
			s+=ma[i][x];
			ma[x][i]=inf;
			ma[i][x]=inf;
			c[i]=true;
			dfs(i);
			s-=l;
			ma[x][i]=l;
			ma[i][x]=l;
			c[i]=false;
		}
	}
		
		
} 
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) ma[i][j]=0;
			else ma[i][j]=inf;
		}
	}
	int minn=inf;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		ma[a[i].u][a[i].v]=a[i].w;
		ma[a[i].v][a[i].u]=a[i].w; 
			if(a[i].w<minn){
				flag=i;
				minn=a[i].w;
			}
		}
		if(k==0){
			s+=a[flag].w;
			ma[a[flag].u][a[flag].v]=inf;
			dfs(a[flag].u);
			dfs(a[flag].v);
			cout<<minnn<<endl;
		}
		return 0;
}
