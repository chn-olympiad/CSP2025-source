#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e05 * 5 + 7, N = 1e06 + 7;

#define int long long

int n, m;

int k, a[MAXN];

int sum[MAXN], lst[MAXN];

int tr[MAXN << 2], tag[MAXN << 2];

void addtag(int l, int r, int p, int val)
{
	tr[p] += (r - l + 1) * val;
	tag[p] += val;
	return ;
}

void pushdown(int l, int r, int p)
{
	if(tag[p])
	{
		int mid = (l + r) >> 1;
		addtag(l, mid, p << 1, tag[p]);
		addtag(mid + 1, r, p << 1 | 1, tag[p]);
		tag[p] = 0;
	}
	return ;
}

void upd(int pl, int pr, int l, int r, int p, int val)
{
	if(l > pr or r < pl)
		return ;
	if(pl <= l and r <= pr)
	{
		addtag(l, r, p, val);
		return ;
	}
	pushdown(l, r, p);
	int mid = (l + r) >> 1;
	if(pl <= mid)
		upd(pl, pr, l, mid, p << 1, val);
	if(pr > mid)
		upd(pl ,pr, mid + 1, r, p << 1 | 1, val);
	tr[p] = tr[p << 1] + tr[p << 1 | 1];
	return ;
}

int qry(int pl, int pr, int l, int r, int p)
{
	if(l > pr or r < pl)
		return 0;
	if(pl <= l and r <= pr)
		return tr[p];
	pushdown(l, r, p);
	int mid = (l + r) >> 1;
	int ans = 0;
	if(pl <= mid)
		ans += qry(pl, pr, l, mid, p << 1);
	if(pr > mid)
		ans += qry(pl ,pr, mid + 1, r, p << 1 | 1);
	return ans;
}

signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int ans = 0;
	
	scanf("%lld%lld", &n, &k);
	
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] ^ a[i];
		
	for(int i = n; i >= 1; i--)
	{
		int r = sum[i - 1] ^ k;
		lst[sum[i]] = i;
		int pos = 0;
		if(sum[i] == r)
			pos = i;
		else
		{
			if(lst[r])
				pos = lst[r];
			else
				pos = 0;
		}
		if(!pos)
			continue;
		else
		{
			int s = qry(i, pos, 1 , n, 1);
			if(s > 0)
				continue;
			++ans;
			upd(i, pos, 1, n ,1, 1);
		}
	}
	
	printf("%lld", ans);
		
	return 0;
}
