#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int t, n, cnt[5];
struct Node
{
	int x, y, z, im, mx, sc, mxid, scid;
}a[N];
bool cmp(Node a, Node b)
{
	return a.im > b.im;
}
void Main()
{
	scanf("%lld", &n);
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].z);
		int mx = max({a[i].x, a[i].y, a[i].z}), sc, mxid, scid;
		if(mx == a[i].x)
		{
			mxid = 1;
			if(a[i].y >= a[i].z)sc = a[i].y, scid = 2;
			else sc = a[i].z, scid = 3;
		}
		if(mx == a[i].y)
		{
			mxid = 2;
			if(a[i].x >= a[i].z)sc = a[i].x, scid = 1;
			else sc = a[i].z, scid = 3;
		}
		if(mx == a[i].z)
		{
			mxid = 3;
			if(a[i].x >= a[i].y)sc = a[i].x, scid = 1;
			else sc = a[i].y, scid = 2;
		}
		a[i].mx = mx, a[i].sc = sc, a[i].mxid = mxid, a[i].scid = scid, a[i].im = mx - sc;
	}
	sort(a + 1, a + n + 1, cmp);
	cnt[1] = cnt[2] = cnt[3] = 0;
	for(int i = 1; i <= n; i++)
	{
		if(cnt[a[i].mxid] < n / 2)//neng xuan zui da de
		{
			ans += a[i].mx;
			cnt[a[i].mxid]++;
		}
		else//xuan ci da de
		{
			ans += a[i].sc;
			cnt[a[i].scid]++;
		}
	}
	printf("%lld\n", ans);
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while(t--)Main();
	return 0;
}
