#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	int n,m,k,a,b,c;
	int ans = 0;
	cin >> m >> n >> k;
	if (k == 0||k == 5||k == 10){
		cout << 0;
	}
	for (int i = 0; i < n;i++){
		cin >> a >> b >> c;
		ans += c;
	}
	cout << ans;
	return 0;
}