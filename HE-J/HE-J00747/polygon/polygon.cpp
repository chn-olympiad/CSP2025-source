#include <bits/stdc++.h>
using namespace std;
int a[5555];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	long long ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n < 3){
		cout << 0;
		return 0;
	}
	sort(a+1, a+n+1);
	for(int i = 3; i <= n; i++){
		int b[5555] = {0};
		for(int j = n; j > n-i; j--){
			b[j] = 1;
		}
		do{
			int maxn = -1, sum = 0;
			for(int j = 1; j <= n; j++){
				if(b[j] == 1){
					if(a[j] > maxn){
						maxn = a[j];
					}
					sum += a[j];
				}
			}
			if(sum > maxn*2){
				ans++;
			}
		}while(next_permutation(b+1, b+n+1));
	}
	cout << ans % 998244353;
	return 0;
}
