#include<bits/stdc++.h>
#define N 501000
#define ll long long
using namespace std;
ll n, k, a[N], ans, t = 1, step;
bool book[N];
struct node{
	ll x, y;
}b[N];
bool check( ll s ){
	for ( int j = b[s].x; j <= b[s].y; j++ ){
		if ( book[j] ){
			return 0;
		}
	}
	return 1;
}
void dfs( ll num, ll sum ){
	if ( num > step ){
		ans = max( ans, sum );
		return;
	}
	for ( int i = num; i <= step; i++ ){
		if ( check(i) ){
			for ( int j = b[i].x; j <= b[i].y; j++ ){
				book[j] = 1;
			}
			return dfs(num + 1, sum + 1);
			for ( int j = b[i].x; j <= b[i].y; j++ ){
				book[j] = 0;
			}
		}
	}
	return dfs(num + 1, sum);
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for ( int i = 1; i <= n; i++ ){
		cin >> a[i];
	}
	while ( t <= n ){
		ll l, r, sum = 0;
		for ( int i = 1; i <= n - t + 1; i++ ){
			l = i, r = i + t - 1, sum = a[l];
			for ( int j = l + 1; j <= r; j++ ){
				sum ^= a[j];
			}
			if ( sum == k ){
				step++;
				b[step].x = l, b[step].y = r;
			}
		}
		t++;
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}