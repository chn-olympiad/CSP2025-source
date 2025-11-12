#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 5;
const int mod = 998244353;
int n;
ll ans;
int a[N];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		int sum = 0;
		int maxn = -114;
		for(int j = 1;j <= i;j++){
			if(i - j < 3) break;
			sum += a[j];
			if(a[j] > maxn){
				maxn = a[j];
			}
		}
		if(sum > maxn * 2) ans++;
		ans %= mod;
	}
	cout << ans;
	return 0;
}
