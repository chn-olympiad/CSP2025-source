#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int a[5005], n;
unsigned long long ans = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	if(a[1] == 1){
		int l = 3;
		while(l <= n){
			ans += n - l + 1;
			ans %= mod;
			l++;
		}
		cout << ans % mod;
	}
	
	return 0;
}
