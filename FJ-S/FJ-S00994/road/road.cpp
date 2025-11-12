#include<bits/stdc++.h>
using namespace std;
struct sum{
	int u;
	int v;
	int w;
}a[1000005];
int b[25][1000005],c[10005][10005],vis[10005][10005];
int minn[1000005];
int cmp(sum a,sum b){
	return a.w < b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i <= m;++i){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	memset(minn,1000000005,sizeof(minn));
	for(int i = 1;i <= k;++i){
		for(int j = 0;j <= n;++j){
			cin>>b[i][j];
		}
	}
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= k;++j){
			minn[i] = min(minn[i],b[j][i]);
		}
	}
	for(int i = 1;i <= n;++i){
		for(int j = i+1;j <= n;++j){
			c[i][j] = minn[i] + minn[j];
		}
	}
	long long ans = 0;
	for(int i = 1;i <= m;++i){
		if(vis[a[i].u][a[i].v]){
			continue;
		}
		if(a[i].w > minn[a[i].u] + minn[a[i].v]){
			ans += minn[a[i].u] + minn[a[i].v];
			vis[a[i].u][a[i].v] = 1;
			vis[a[i].v][a[i].u] = 1;
		}
		else{
			ans += a[i].w; 
			vis[a[i].u][a[i].v] = 1;
			vis[a[i].v][a[i].u] = 1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
