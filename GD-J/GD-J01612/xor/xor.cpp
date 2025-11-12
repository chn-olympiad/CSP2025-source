#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[1000010];
int a[1000010];
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int maxx = -1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxx = max(a[i], maxx);
	}
	if(maxx <= 1){
		if(k == 1){
			int ans = 0;
			for(int i = 1; i <= n; i++){
				if(a[i] == 1)ans++;
			}
			cout << ans;
		}
		else{
			int ans = 0;
			for(int i = 1; i <= n; i++){
				if(a[i] == 0)ans++;
			}
			for(int i = 1; i <= n - 1; i++){
				if(a[i] == a[i + 1] && a[i] == 1){
					ans++;
					i++; 
				}
			}
			cout << ans;
		} 
		return 0;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		int sum = 0;
		f[i] = -1;
		for(int j = i; j <= n; j++){
			sum ^= a[j];
			if(sum == k){
				f[i] = j;
				break;	
			}
		}
		if(f[i] == -1){
			f[i] = n + 1;
			cnt++;
		}
	}
	if(cnt == n){
		cout << 0 << endl;
		return 0;
	}	
	int p = 1;
	int ans = 0;
	while(p <= n){
		int minn = n + 1;
		for(int i = p; i <= n; i++){
			minn = min(minn, f[i]);
		}
		if(minn != n + 1){
			ans++;
		}
		p = minn + 1;
	}
	cout << ans;
}
