#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
int n,m,k,ans,cnt;
struct edge{
	int u,v,w;
	bool operator < (const edge& x)const{
		return w < x.w;
	}
}a[N*1000];
int mp[N][N];
bool vis[N];
int c;
int b[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=w;
		mp[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>b[j];
		}
		for(int j=1;j<=n;j++)
			for(int kk=i+1;kk<n;kk++)
				if(b[j]+b[kk]<mp[j][kk])
					mp[j][kk]=b[j]+b[kk],mp[kk][j]=b[j]+b[kk];
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(mp[i][j])
				a[++cnt]={i,j,mp[i][j]};
	sort(a+1,a+m+1);	
	for(int i=1;i<=cnt;i++){
		if(!vis[a[i].u]||!vis[a[i].v]){
			vis[a[i].u]=1;
			vis[a[i].v]=1;
			ans+=a[i].w;
		}
	}
	cout<<ans;
	return 0;
}
