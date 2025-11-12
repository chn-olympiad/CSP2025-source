#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 1;
int T, n;
struct node
{
	int x, y, z;
}a[N];
struct node2
{
	int x, id;
};
bool cmpx(node2 x, node2 y)
{
	return x.x - max(a[x.id].y, a[x.id].z) < y.x - max(a[y.id].y, a[y.id].z);
}
bool cmpy(node2 x, node2 y)
{
	return x.x - max(a[x.id].x, a[x.id].z) < y.x - max(a[y.id].x, a[y.id].z);
}
bool cmpz(node2 x, node2 y)
{
	return x.x - max(a[x.id].x, a[x.id].y) < y.x - max(a[y.id].x, a[y.id].y);
}
void solve()
{
	cin >> n;
	vector<node2> xzx, xzy, xzz;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	int ans = 0;
	int totx = 0, toty = 0, totz = 0;
	for(int i = 1; i <= n; i++)
	{
		int cnt = max(a[i].x, max(a[i].y, a[i].z));
		if(a[i].x == cnt) 
		{
			totx++;
			xzx.push_back({a[i].x, i});
		}
		else if(a[i].y == cnt) 
		{
			toty++;
			xzy.push_back({a[i].y, i});
		}
		else
		{ 
			totz++;
			xzz.push_back({a[i].z, i});
		}
		ans += cnt;
	}
	if(totx * 2 > n)
	{
		sort(xzx.begin(), xzx.end(), cmpx);
		for(int i = 0; totx * 2 > n; i++)
		{
			totx--;
			ans -= xzx[i].x;
			ans += max(a[xzx[i].id].y, a[xzx[i].id].z);
		}
	}
	else if(toty * 2 > n)
	{
		sort(xzy.begin(), xzy.end(), cmpy);
		for(int i = 0; toty * 2 > n; i++)
		{
			toty--;
			ans -= xzy[i].x;
			ans += max(a[xzy[i].id].x, a[xzy[i].id].z);
		}
	}
	else if(totz * 2 > n)
	{
		sort(xzz.begin(), xzz.end(), cmpz);
		for(int i = 0; totz * 2 > n; i++)
		{
			totz--;
			ans -= xzz[i].x;
			ans += max(a[xzz[i].id].x, a[xzz[i].id].y);
		}
	}
	cout << ans << "\n";
	return;
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--) solve();
	return 0;
}
/*
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
125440



*/
