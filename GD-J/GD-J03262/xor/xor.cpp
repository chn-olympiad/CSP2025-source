#include <bits/stdc++.h>

using namespace std;
const int maxn = 500004;
int n, k, a[maxn];

struct nd
{
	int l, r;
	int val;
};
nd segment_tree[maxn*4];

inline int fa(int u) { return u>>1; }
inline int lc(int u) { return u<<1; }
inline int rc(int u) { return (u<<1)+1; }

vector<pair<int, int>> satisfy_range; // pair: r, l. sort this

class SegmentTree
{
private:
	nd* segt;
public:
	SegmentTree()
	{ segt = segment_tree; }
	
	void push_up(int cur)
	{ segt[cur].val = segt[lc(cur)].val ^ segt[rc(cur)].val; }
	
	void build(int cur, int l, int r)
	{
		segt[cur].l = l;
		segt[cur].r = r;
		if(l == r)
		{
			segt[cur].val = a[l];
			// printf("[%d, %d]: val = %d\n", l, r, segt[cur].val);
			// if(segt[cur].val == k)
			//	satisfy_range.push_back({r, l});
			return;
		}
		int mid = (l+r) / 2;
		build(lc(cur), l, mid);
		build(rc(cur), mid+1, r);
		push_up(cur);
		// printf("[%d, %d]: val = %d (k=%d)\n", l, r, segt[cur].val, k);
		if(segt[cur].val == k)
		{
			// printf("Good!\n");
			// satisfy_range.push_back({r, l});
		}
	}
	
	int query(int cur, int l, int r)
	{
		if(l <= segt[cur].l && segt[cur].r <= r)
			return segt[cur].val;
		int mid = (segt[cur].l + segt[cur].r) / 2;
		int ret = -1;
		if(l <= mid) ret = query(lc(cur), l, r);
		if(r > mid)
		{
			if(ret == -1) ret = query(rc(cur), l, r);
			else ret = ret ^ query(rc(cur), l, r);
		}
		return ret;
	}
};

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	SegmentTree seg_tree;
	seg_tree.build(1, 1, n);
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			int val = seg_tree.query(1, l, r);
			if(val == k) satisfy_range.push_back({r, l});
		}
	}
	sort(satisfy_range.begin(), satisfy_range.end());
	// for(auto u : satisfy_range) printf("[%d, %d]\n", u.second, u.first);
	//// 显然线段树的区间无法覆盖所有情况，:(
	//// then how to n log n ? 
	//// 位数很小 可能应该从位数入手 ，但我先打个n^2 logn , 60pts
	//// 13~16 和 17~20 差常数，难道还要卡 log ? 
	int cur_l = 0, cur_r = 0;
	long long cnt = 0;
	for(auto u : satisfy_range)
	{
		if((cur_l <= u.second && u.second <= cur_r) ||
			(cur_l <= u.first && u.first <= cur_r) ||
			(u.second <= cur_l && cur_l <= u.first) ||
			(u.second <= cur_r && cur_r <= u.first)) continue;
		cur_l = u.second, cur_r = u.first;
		cnt++;
	}
	printf("%lld\n", cnt);
	return 0;
}
 
