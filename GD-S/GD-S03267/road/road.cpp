#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,k;
ll f[10005];
ll find (ll x) {
	if (f[x] == x) return x;
	return f[x] = find (f[x]);
}
struct qi {
	ll a,b,c;
} d[1000005];
bool cmp (qi a,qi b) {
	return a.c < b.c;
}
ll cnt = 0;

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> d[i].a >> d[i].b >> d[i].c;
	}
	sort (d + 1,d + n + 1,cmp);
	ll t = 0;
	for (int i = 1; i <= m; i++) {
		if (find (d[i].a) != find (d[i].b)) {
			f[find (d[i].a)] = d[i].b;
			cnt += d[i].c;
			t ++;
			if (t == n - 1)
				break;
		}
	}
	cout << cnt << endl;
	return 0;
}
