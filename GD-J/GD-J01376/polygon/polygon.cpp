#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010;
long long a[maxn] , A[maxn];
long long sum[maxn];
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	int n;
	cin >> n;
	int max_1 = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	sort(a + 1 , a + 1 + n);
	if(a[n] == 1){
		long long ans = 0;
		A[0] = 1;
		for(int i = 1 ; i <= n ; i++){
			A[i] = (A[i - 1] * i) % 998244353;
		}
		for(int i = 3 ; i <= n ; i++){
			ans += A[n] / A[i];
		}
		cout << ans;
		return 0;
	}
	for(int i = 1 ; i <= n ; i++){
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 0;
	for(int i = 3 ; i <= n ; i++){
		if(sum[i - 1] > a[i]){
			++ans;
		}
		if(i > 3){
			for(int j = 1 ; j < i ; j++){
				if(sum[i - 1] - a[j] > a[i]){
					ans++;
//					cout << "1: " << j << '\n';
				}
				else break;
			}
		}
		if(i > 4){
			for(int j = 1 ; j < i ; j++){
				for(int k = j + 1 ; k < i ; k++){
					int Sum = sum[k] - sum[j - 1];
					if(sum[i - 1] - Sum > a[i] && n - k >= 2){
						ans++;
//						cout << "2: " << j << ' ' << k << '\n';
					}
					else break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
