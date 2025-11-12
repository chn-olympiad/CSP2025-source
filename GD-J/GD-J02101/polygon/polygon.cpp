#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353, N = 5e3 + 7;
int n, s[N];
long long ans;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	sort(s + 1, s + n + 1);
	for (int i = 1; i <= n-2; i++) {
		for (int j = i + 2; j <= n; j++) {
			long long sum = 0, maxs = 0;
			for (int k = i;k<=j;k++){
				sum += s[k];
				if (s[k]>maxs){
					maxs = s[k];
				}
			}
			if (maxs * 2 < sum) {
				ans = (ans+1)%MOD;
			}
		}
	}
	cout<<ans<<"\n";
	
	return 0;
}
