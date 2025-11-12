#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum=0,l;
int vis[10010],cco[100010],co[10010][10010];
struct road{
	long long u,v,w; 
}a[10000010];
void dfs(int now){
	int cost=0x3f3f3f3f;
	if(now==n+1){
		return;
	}
	for(int i=1;i<=n;++i){
		if(a[i].u==now || a[i].v==now){
			int yhf=a[i].w;
			cost=min(cost,yhf);
		}
	}
	for(int i=1;i<=k;++i){
		if(cost>(cco[i]+co[i][now])){
			cost=min(cost,cco[i]+co[i][now]);
			cco[i]=0;
		}
	}
	sum+=cost;
	dfs(now+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i].u>>a[i].v>>a[i].w;
	} 
	for(int i=1;i<=k;++i){
		cin>>cco[i];
		for(int j=1;j<=n;++j){
			cin>>co[i][j];
		}
	}	
	dfs(1);
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 