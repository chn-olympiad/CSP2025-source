#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1500;
ll a[N], n, m, R, p, l, r;
bool cmp(ll u, ll v){return u > v;}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	freopen("seat.in", "r", stdin);freopen("seat.out", "w", stdout);
	cin >> p >> m;n = p * m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	R = a[1];
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1;i <= n;i ++) if(a[i] == R) {R = i;break;}
	l = 1, r = 0;
	for(int i = 1;i <= R;i ++)
	{
		if(l & 1)
		{
			r ++;
			if(r > p) l ++, r = p;
		}
		else
		{
			 r --;
			 if(r < 1) l ++, r = 1;
		}
	}
	cout << l << ' ' << r << '\n';
	return 0;
}
