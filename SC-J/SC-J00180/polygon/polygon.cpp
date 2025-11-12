#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, a[5000], cnt;
const int N = 998244353;
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 3; i <= n; i++){
		int m = 1;
		for(int j = n; j >= n - i + 1; j--){
			m *= j;
			m %= N;
		}
		for(int j = 1; j <= i; j++){
			m /= j;
			m %= N;
		}
		cnt += m;
	}
	cout << cnt;
	return 0;
}