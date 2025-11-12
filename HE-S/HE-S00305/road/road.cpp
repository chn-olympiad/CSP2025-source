#include<bits/stdc++.h>
using namespace std;
long long n,m,k; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	long long ans = 0,ans1[n+5] = {0},ans2;
	long long u[n+5],v[n+5],w[n+5],c[k+5],a[n+5][n+5];
	for(int i = 1;i <= m;i++){
		cin >> u[i] >> v[i] >> w[i];
		ans+=w[i];
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}
	int cnt = 1;
	for(int i = 1;i <= k;i++){
		if(c[i] == 0){
			for(int j = 1;j <= n;j++){
				ans1[cnt]+=a[i][j];
			}
			cnt++;
		}
	}
//	cout << ans1[1] << " " << ans1[2] << endl;
	ans2 = ans1[1];
	for(int i = 1;i <= k;i++){
		if(ans1[i]<ans2){
			ans2 = ans1[i];
		}
	}
//	cout << ans2 << endl;
	if(ans < ans2){
		cout << ans << "\n";
	}
	else{
		cout << ans2 << "\n";
	}
	return 0;
}

