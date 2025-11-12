#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,k;
int a[10005][10005];
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,-1,sizeof(a));
	for(int i=1; i<=m; i++) {
		int x,y,w;
		cin>>x>>y>>w;
		if(x>y) swap(x,y);
		if(a[x][y]==-1) a[x][y]=w;
		else a[x][y]=min(a[x][y],w);
	}
	if(k==0) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(a[i][j]!=-1) ans+=a[i][j];
			}
		}
		cout<<ans<<endl;
	} else {
		int sum=1e18;
		for(int i=1; i<=k; i++) {
			int cnt=0;
			int c;
			cin>>c;
			for(int j=1; j<=n; j++) {
				int x;
				cin>>x;
				cnt+=x;
			}
			sum=min(sum,cnt);
		}
		cout<<sum<<endl;
	}
	return 0;
}
