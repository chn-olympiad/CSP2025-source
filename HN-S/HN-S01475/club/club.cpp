#include <bits/stdc++.h>

using namespace std;
const int N = 100010;

int n;
struct Node
{
	int a, b, c;
	int lv, mv, rv;
	int lt, mt, rt;
	bool operator < (const Node& W) const
	{
		if (lv - mv != W.lv - W.mv) return lv - mv < W.lv - W.mv;
		if (lv - rv != W.lv - W.rv) return lv - rv < W.lv - W.rv;
		return a < W.a;	
	}
} arr[N];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > heap[3];

void change(Node& p)
{
	p.lv = max({p.a, p.b, p.c}), p.rv = min({p.a, p.b, p.c});
	p.mv = p.a + p.b + p.c - p.lv - p.rv;
	if (p.lv == p.a) p.lt = 0;
	else if (p.lv == p.b) p.lt = 1;
	else p.lt = 2;
	if (p.mv == p.a) p.mt = 0;
	else if (p.mv == p.b) p.mt = 1;
	else p.mt = 2;
	if (p.rv == p.a) p.rt = 0;
	else if (p.rv == p.b) p.rt = 1;
	else p.rt = 2;
}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i ++ ) 
	{
		cin >> arr[i].a >> arr[i].b >> arr[i].c;
		change(arr[i]);
	}
	sort(arr + 1, arr + n + 1);

	int ans = 0, cnt[3] = {0, 0, 0};
	for (int i = 1; i <= n; i ++ )
	{
		pair<int, int> t = {0, 0};
		if (heap[arr[i].lt].size())
			t = heap[arr[i].lt].top();
		if (cnt[arr[i].lt] + 1 <= (n >> 1)) 
		{
			ans += arr[i].lv;
			cnt[arr[i].lt] ++ ;
			heap[arr[i].lt].push({arr[i].lv - arr[i].mv, arr[i].mt});
		}
		else if (t.first < arr[i].lv - arr[i].mv)
		{
			ans += arr[i].lv - t.first;
			cnt[t.second] ++ ;
			heap[arr[i].lt].pop();
			heap[arr[i].lt].push({arr[i].lv - arr[i].mv, arr[i].mt});
		}
		else
		{
			ans += arr[i].mv;
			cnt[arr[i].mt] ++ ;
			heap[arr[i].mt].push({arr[i].mv - arr[i].rv, arr[i].rt});
		}
	}
	cout << ans << endl;
}

void init()
{
	while (heap[0].size()) heap[0].pop();
	while (heap[1].size()) heap[1].pop();
	while (heap[2].size()) heap[2].pop();
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int T; cin >> T;
	while (T -- )
	{
		solve();
		init();
	}

	return 0;
}
