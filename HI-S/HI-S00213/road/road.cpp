#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000005],v[1000005],w[1000005];
int minn[15];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	if(k==0){
		ans=0;
		for(int i = 1;i <= m;i++){
			ans+=w[i];
		}
		cout << ans;
		return 0;
	}
	sort(w+1,w+m+1);
	ans=0;
	for(int i = 1;i <= min(0,m-k);i++){
		ans+=w[i];
	}
	cout << ans;
	return 0;
}
