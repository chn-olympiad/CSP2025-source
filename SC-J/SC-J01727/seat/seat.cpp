#include <queue>
#include <string>
#include <bits/stdc++.h>
#define ll long long 
#define int ll
#define fi first
#define se second
#define mk make_pair
#define mem(a , x) memset(a , x , sizeof(a))
#define ls x << 1
#define rs x << 1 | 1
using namespace std;
ll const N = 1e5 + 10;
ll n , m , a[N] , r;
signed main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i ++) cin >> a[i];
	r = a[1];
	sort(a + 1 , a + n * m + 1 , greater<ll>());
	ll pos = 0;
	for (int i = 1;i <= n * m;i ++)
		if (a[i] == r){
			pos = i;
			break;
		}
	ll x = pos % n , y = (pos - 1) / n + 1;
	if (!x) x = n;
	if (y % 2 == 0) x = n - x + 1;
	cout << y << " " << x << "\n";
	return 0;
}
/*

*/