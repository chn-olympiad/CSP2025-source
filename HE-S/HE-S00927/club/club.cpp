#include <bits/stdc++.h>
using namespace std;
int n,t,a[100005][3],cnt[3];
int vis[100005][3],d[100005];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for (int i = 1;i<=n;i++){
			for (int j = 1;j<=3;j++){
				cin >> a[i][j];
			}
			if (a[i][1]>=a[i][2]&&a[i][2] >=a[i][3]){
				vis[i][1] = 1;
				vis[i][2] = 2;
				vis[i][3] = 3;
			}
			if (a[i][1]>=a[i][3]&&a[i][2] <=a[i][3]){
				vis[i][1] = 1;
				vis[i][2] = 3;
				vis[i][3] = 2;
			}
			if (a[i][1]<=a[i][2]&&a[i][1] >=a[i][3]){
				vis[i][1] = 2;
				vis[i][2] = 1;
				vis[i][3] = 3;
			}
			if (a[i][1]>=a[i][2]&&a[i][3] >=a[i][1]){
				vis[i][1] = 2;
				vis[i][2] = 3;
				vis[i][3] = 1;
			}
			if (a[i][1]<=a[i][2]&&a[i][2] <=a[i][3]){
				vis[i][1] = 3;
				vis[i][2] = 2;
				vis[i][3] = 1;
			}
			if (a[i][1]<=a[i][3]&&a[i][2] >=a[i][3]){
				vis[i][1] = 3;
				vis[i][2] = 1;
				vis[i][3] = 2;
			}
		}
		cnt[1] = 0;
		cnt[2] = 0;
		cnt[3] = 0;
		for (int i = 1;i<=n;i++){
			for (int j = 1;j<=3;j++){
				
				if (vis[i][j] == 1) cnt[j]++;
			}
			
		}
		int maxx=INT_MIN,id = 0;
		for (int i = 1;i<=3;i++){
			if (cnt[i]>=maxx){
				maxx = cnt[i];
				id = i;
			}
		}
		int ans = 0,x=n/2;
		for (int i = 1;i<=n;i++){
			for (int j = 1;j<=3;j++){
				if (vis[i][j] == 1) ans+=a[i][j];
			}
		}
		
		if (maxx<=x){
			
			cout << ans << endl;
		}
		if (maxx>x){
			memset(d,0,sizeof(d));
			
			for (int i = 1;i<=n;i++){
				if (vis[i][id]==1){
					int shou,ci;
					for (int j = 1;j<=3;j++){
						if (vis[i][j]==1) shou = a[i][j];
						if (vis[i][j]==2) ci = a[i][j];
					}
					d[i] = shou-ci;
				}
			}
			sort(d+1,d+n+1);
			int j = 1;
			for (int i = 1;i<=n,j<=maxx-x;i++){
				if (d[i]==0) continue;
				ans-=d[i];
				j++;
			}
			cout << ans << endl;
		}
		
	}
	return 0;
}
