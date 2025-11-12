#include<bits/stdc++.h>
using namespace std;
#define l first
#define r second
using P = pair<int, int>;
const int N = 5e5 + 5;
int a[N], sa[N];
vector<P> itv;

bool cmp(P x, P y)
{
	return x.r < y.r;
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sa[i] = sa[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int sum = sa[j] ^ sa[i - 1];
			if (sum == k) itv.emplace_back(i, j);
		}
	}
	sort(itv.begin(), itv.end(), cmp);
	int end = itv[0].r, cnt = 1;
	for (int i = 1; i < itv.size(); i++)
	{
		if (itv[i].l <= end) continue;
		cnt++;
		end = itv[i].r;
	}
	cout << cnt << '\n';
	return 0;
}
