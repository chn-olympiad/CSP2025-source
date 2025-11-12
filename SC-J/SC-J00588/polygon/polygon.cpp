#include<bits/stdc++.h>
using namespace std;
int n, a[5005], f = 1;
long long res;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(a[i] > 1) f = 0;
	}
	if(n == 3){
		int sum = 0, mx = 0;
		for(int i = 1; i <= n; i ++){
			sum += a[i];
			mx = max(a[i], mx);
		}
		if(sum > 2 * mx){
			cout << 1 << "\n";
			return 0;
		}
		cout << 0 << "\n";
		return 0; 
	}
	if(f){
		for(int i = 1; i <= n; i ++){
			long long ans = 1;
			for(int j = i+1; j <= n;j ++){
				ans *= j;
			}
			res += ans;
		}
		cout << res << "\n";
	}
	return 0;
}
