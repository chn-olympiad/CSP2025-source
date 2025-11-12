#include <bits/stdc++.h>
using namespace std;
long long a[111111];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, ans = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n == 1 && k == a[1]){
		cout << 1;
		return 0;
	}else if(n == 1 && k != a[1]){
		cout << 0;
		return 0;
	}
	int sum = 0;
	for(int i = 1; i <= n; i++){
		int p = i;
		for(int j = 1; j <= n; j++){
			int ans = a[j];
			for(int o = j+1; o < j+p; o++){
				if(o > n-i){
					ans = k-1;
					break;
				} 
				ans ^= a[o];
			}
			if(ans == k){
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
}
