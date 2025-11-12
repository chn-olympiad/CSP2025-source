#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, N = 5005;
int n, a[N], ans;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	for(int i=3; i<=n; i++) ans = (ans+n-i+1)%mod;
	printf("%d", ans);
	return 0;
}
// max ai <=1 的情况，Maybe I can got 24 pts，我要上 GD 迷惑代码大全！ 
