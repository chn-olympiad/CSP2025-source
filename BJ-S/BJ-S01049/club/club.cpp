#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;

int T, n, a[N][3], m[3], b[N], c[N];
vector<int> v; ll ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	while(T--)
	{
		cin >> n; ans = m[0] = m[1] = m[2] = 0; c[0] = 3; v.clear();
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) b[i] = 0, c[i] = max(a[i][1], a[i][2]);
			if(a[i][1] > a[i][0] && a[i][1] >= a[i][2]) b[i] = 1, c[i] = max(a[i][0], a[i][2]);
			if(a[i][2] > a[i][0] && a[i][2] > a[i][1]) b[i] = 2, c[i] = max(a[i][0], a[i][1]);
			m[b[i]]++, c[i] = a[i][b[i]] - c[i], and += max(a[i][0], max(a[i][1], a[i][2]));
		}
		for(int i = 0; i < 3; i++) if(2 * m[i] > n) c[0] = i;
		if(c[0] == 3) {cout << ans << endl; continue; }
		for(int i = 1; i <= n; i++) if(b[i] == c[0]) v.push_back(c[i]);
		sort(v.begin(), v.end());
		for(int i = m[c[0]]; 2 * i > n; i--) ans -= v[m[c[0]] - i];
		cout << ans << endl;
	}
	
	return 0;
}