#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[50010], k;
vector<vector<ll>> mp;
ll ans[50010];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n + 5; i++) mp.push_back({0});
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == k){
			mp[i].push_back(i);
			mp[i][0]++;
		}
	}
	for(int i = 1; i <= n - 1; i++){
		ll o = a[i];
		for(int l = i + 1; l <= n; l++){
			o = o ^ a[l];
			if(o == k){
				mp[i].push_back(l);
				mp[i][0]++;
			}
		}
	}
	for(int i = n; i >= 1; i--){
		ans[i] = ans[i + 1];
		if(mp[i][0] != 0){
			for(int l = 1; l <= mp[i][0]; l++){
				ans[i] = max(ans[i], ans[mp[i][l] + 1] + 1);
			}
		}
	}
	cout << ans[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
