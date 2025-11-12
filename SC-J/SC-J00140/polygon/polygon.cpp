#include<bits/stdc++.h>
#define ll long long
#define _for(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int M = 998244353;
int n, a[5005], s;
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	_for(i, 1, n) cin >> a[i], s += a[i];
	sort(a + 1, a + n + 1, greater<int>());
	if(n == 3){
		if(s > 2 * a[1]) cout << 1;
		else cout << 0;
	}
	return 0;
}