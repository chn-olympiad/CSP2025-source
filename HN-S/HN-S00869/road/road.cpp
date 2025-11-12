#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,k;
int x[N],y[N],u[N];
int a[1005][1005],ans[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i]>>u[i];
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		ans[i]=u[i];
		for(int j=1;j<=k;j++){
			ans[i]=min(ans[i],(a[j][x[i]]+a[j][y[i]]));
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=ans[i];
	}
	cout<<sum;
	return 0;
}
