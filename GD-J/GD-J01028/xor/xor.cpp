#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int n , k , a[N] , sum[N] , ans , id , m[2000010];
int main () {
	freopen ("xor.in" , "r" , stdin);
	freopen ("xor.out" , "w" , stdout);
	ios::sync_with_stdio (0);
	cin.tie (0); cout.tie (0);
	memset (m , -1 , sizeof m);
	m[0] = 0;
	cin >> n >> k;
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];
		sum[i] = a[i] ^ sum[i - 1];
		int x = sum[i] ^ k;
//		cout << x << ' '; 
		if (id <= m[x]) {
			ans ++;
			id = i;
		}
//		cout << id << '\n';
		m[sum[i]] = i;
	}
	cout << ans;	
	
	return 0;
}
