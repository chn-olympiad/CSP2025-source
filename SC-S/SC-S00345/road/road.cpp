#include<bits/stdc++.h>//666
#define int long long
using namespace std;
int n,m,k,u,v,w,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	vector<vector<int> > G(m+1,vector<int>(n+1,1e9));
	vector<int> c(k+1,1e9);
	vector<vector<int> > a(k+1,vector<int>(n+1));
	vector<int> t(m+k*n+1);
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		G[u][v]=w;
		t[i]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	int cnt=m;
	for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) t[++cnt]=a[i][j]+c[i];
	sort(t.begin(),t.end());
	for(int i=1;i<=n-1;i++) ans+=t[i];
	cout<<ans;
	return 0;
}