#include <bits/stdc++.h>
using namespace std;
struct ct{
	int u,v,w;
}e[100005];
bool cmp(ct x,ct y){
	return x.w>y.w;
}
int c[15],a[15][1005],vis[1005];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>e[i].u>>e[i].v>>e[i].w;
		vis[e[i].u]++;
		vis[e[i].v]++;
		ans+=e[i].w; 
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	//cout<<ans<<endl;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++){
		if(vis[e[i].u]-1>0&&vis[e[i].u]-1>0){
			//cout<<vis[e[i].u]<<" "<<vis[e[i].v]<<" ";
			vis[e[i].u]--;vis[e[i].v]--;
			ans-=e[i].w;
			//cout<<ans<<endl;
		}
	}
	cout<<ans;
	return 0;
}
