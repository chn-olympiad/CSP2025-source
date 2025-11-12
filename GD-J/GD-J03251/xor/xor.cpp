#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5, V = (1<<21);
int n, k, a[N], f[N], lst[V];
int main(){
	freopen("xor.in", "r", stdin); 
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	memset(lst, -1, sizeof lst);
	int s = 0, ans = 0; lst[0] = 0;
	for(int i = 1; i <= n; i++){
		s ^= a[i];
		f[i] = f[i-1];
		if(lst[s^k] != -1) f[i] = max(f[i], f[lst[s^k]]+1);
		lst[s] = i;
		ans = max(ans, f[i]);
	} cout << ans << '\n';
	return 0;
}
