// C - segtree
// expect pts = 60
// expect diff = idk, green?

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+10;

int n, k;
int a[maxn];
struct Node{
	int l, r, sum;
}t[maxn*4];

int ans;

void pushup(int u)
{
	t[u].sum = t[u*2].sum ^ t[u*2+1].sum;
}

void build(int u, int l, int r)
{
	t[u].l = l;
	t[u].r = r;

	if(l == r)
	{
		t[u].sum = a[l];
		return;
	}

	int mid = (l+r) / 2;
	build(u*2, l, mid);
	build(u*2+1, mid+1, r);
	pushup(u);
}

int query(int u, int l, int r)
{
	if(t[u].r < l || t[u].l > r)
		return 0;

	//cout << t[u].l << ' ' << t[u].r << endl;

	if(l <= t[u].l && r >= t[u].r)
		return t[u].sum;

	return query(u*2, l, r) ^ query(u*2+1, l, r);
}

void sol1()
{
	//cout << "aaa"<< endl;
	int l_limit = 1;
	for(int r = 1 ; r <= n ; r ++)
	{
		for(int l = l_limit ; l <= r ; l ++)
		{
			int xorsum = 0;
			for(int i = l ; i <= r ; i ++)
				xorsum ^= a[i];
			if(xorsum == k)
			{
				//cout << l << ' ' << r << endl;
				ans ++;
				l_limit = r+1;
				break;
			}
		}
	}

}

void sol2()
{
	build(1, 1, n);
	int l_limit = 1;
	for(int r = 1 ; r <= n ; r ++)
	{
		for(int l = l_limit ; l <= r ; l ++)
		{
			if(query(1, l, r) == k)
			{
				//cout << l << ' ' << r << endl;
				ans ++;
				l_limit = r+1;
				break;
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];

	if(n <= 100)
		sol1();
	else
		sol2();

	cout << ans << endl;

	return 0;
}
