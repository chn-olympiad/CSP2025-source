#include<bits/stdc++.h>
using namespace std;
long long n, k, a[5005], s[5005], sum[5005][5005], ans;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		s[i] = s[i-1] ^ a[i];
	}
	if(!f){
		if(k == 1){
			int cnt = 0;
			for(int i = 1; i <= n; i ++){
				if(a[i] == 1){
					cnt ++;
				}
			}
			cout << cnt << "\n";
			return 0;
		}
	}
	for(int l = 1; l <= n; l ++){
		for(int r = l; r <= n; r ++){
			for(int k = l; k <= r; k ++){
				sum[l][r] ^= a[k];
			}
		}
	}
	for(int l = 1; l <= n; l ++){
		for(int r = l; r <= n; r ++){
			if(sum[l][r] == k){
				ans ++;
				l = r;
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
