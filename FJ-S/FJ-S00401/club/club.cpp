#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N][3];
struct node
{
	int id;
	int cost;
};
vector<node> v1, v2, v3;

bool cmp(node a, node b)
{
	return a.cost < b.cost;
}

void solve()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++ ) cin >> a[i][0] >> a[i][1] >> a[i][2];
	v1.clear();
	v2.clear();
	v3.clear();
	for(int i = 1 ; i <= n ; i ++ )
	{
		if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) v1.push_back({i, a[i][0] - max(a[i][1], a[i][2])});
		else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) v2.push_back({i, a[i][1] - max(a[i][0], a[i][2])});
		else v3.push_back({i, a[i][2] - max(a[i][0], a[i][1])});
	}
	if(v1.size() <= (n / 2) && v2.size() <= (n / 2) && v3.size() <= (n / 2))
	{
		int ans = 0;
		for(auto u : v1) ans += a[u.id][0];
		for(auto u : v2) ans += a[u.id][1];
		for(auto u : v3) ans += a[u.id][2];
		cout << ans << "\n";
		return;
	}
	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);
	sort(v3.begin(), v3.end(), cmp);
	if(v1.size() > (n / 2))
	{
		for(int i = 0 ; i < (v1.size() - n / 2) ; i ++ )
			if(a[v1[i].id][1] > a[v1[i].id][2]) v2.push_back(v1[i]);
			else v3.push_back(v1[i]);
		vector<node> tmp;
		for(int i = 0 ; i < n / 2 ; i ++ ) tmp.push_back(v1[v1.size() - i - 1]);
		v1 = tmp;
		int ans = 0;
		for(auto u : v1) ans += a[u.id][0];
		for(auto u : v2) ans += a[u.id][1];
		for(auto u : v3) ans += a[u.id][2];
		cout << ans << "\n";
	}
	if(v2.size() > (n / 2))
	{
		for(int i = 0 ; i < (v2.size() - n / 2) ; i ++ )
			if(a[v2[i].id][0] > a[v2[i].id][2]) v1.push_back(v2[i]);
			else v3.push_back(v2[i]);
		vector<node> tmp;
		for(int i = 0 ; i < n / 2 ; i ++ ) tmp.push_back(v2[v2.size() - i - 1]);
		v2 = tmp;
		int ans = 0;
		for(auto u : v1) ans += a[u.id][0];
		for(auto u : v2) ans += a[u.id][1];
		for(auto u : v3) ans += a[u.id][2];
		cout << ans << "\n";
	}
	if(v3.size() > (n / 2))
	{
		for(int i = 0 ; i < (v3.size() - n / 2) ; i ++ )
			if(a[v3[i].id][0] > a[v3[i].id][1]) v1.push_back(v3[i]);
			else v2.push_back(v3[i]);
		vector<node> tmp;
		for(int i = 0 ; i < n / 2 ; i ++ ) tmp.push_back(v3[v3.size() - i - 1]);
		v3 = tmp;
		int ans = 0;
		for(auto u : v1) ans += a[u.id][0];
		for(auto u : v2) ans += a[u.id][1];
		for(auto u : v3) ans += a[u.id][2];
		cout << ans << "\n";
	}
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T -- ) solve();
	return 0;
}
