#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 5, mod = 998244353;
int n;
int a[N], ans;
int sum[N];
ll jie(int x){
	int t= 1;
	for(int i = 1 ; i <= x; i ++){
		t *= i;
		t %= 10;
	}
	return  t;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		ans *= i;
		ans %= mod;
	}
	sort(a + 1, a + n + 1);
	cout << ans << "\n";
	return 0;
}
