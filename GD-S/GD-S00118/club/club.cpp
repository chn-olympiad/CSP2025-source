#include <bits/stdc++.h>
using namespace std;
int a[1000000][4],vis[4],sum[1000000];
void dfs(int n,bool x,bool y,bool z,int cnt) {
	if(cnt++==n) return ;
	if(x&&(vis[1] <= n/2)) {
		sum[cnt]+=a[cnt][1];
		vis[1]++;
	} else if(y&&(vis[2] <= n/2)) {
		sum[cnt]+=a[cnt][2];
		vis[2]++;
	} else if(z&&(vis[3] <= n/2)) {
		sum[cnt]+=a[cnt][3];
		vis[3]++;
	}
	//cout<<sum[cnt]<<" ";
	dfs(n,true,false,false,cnt);
	dfs(n,false,true,false,cnt);
	dfs(n,false,false,true,cnt);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				cin>>a[i][j];
			}
		}
		dfs(n,false,false,false,0);
		int maxx=-1;
		for(int i=1; i<=n; i++) {
			maxx=max(sum[i],maxx);
		}
		cout<<maxx<<endl;
		for(int i=1; i<=n; i++) {
			sum[i]=0;
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				a[i][j]=0;
			}
		}
		for(int i=1; i<=3; i++) {
			vis[i]=0;
		}
	}
	return 0;
}
