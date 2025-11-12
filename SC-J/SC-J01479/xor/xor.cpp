#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, k, a[N], pre[N];
struct node
{
	int l, r, len;
	bool operator < (const node &other) { return len == other.len ? l < other.l : len < other.len; }	
};
bool flg[N];
inline int getxor(int l, int r) { return pre[l - 1] ^ pre[r]; }

bool check1(int v[N]);
bool check2(int v[N]);
bool check3(int v[N]);

void solve1();
void solve2();
void solve3();

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), pre[i] = pre[i - 1] ^ a[i];
	if (check1(a))
		solve1();
	else if (check2(a))
		solve2();
	else
		solve3();
	return 0;
}

void solve1()
{
	if (k == 0)
		printf("%d", n / 2);
	else if (k == 1)
		printf("%d", n);
	else
		printf("0");
}

void solve2()
{
	if (k == 1)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] == 1)
				cnt++;
		printf("%d", cnt);
	}
	else if (k == 0)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] == 0)
				cnt++;
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 1)
			{
				int len = 0, j;
				for (j = i; j <= n; j++)
				{
					if (a[j] == 0)
						break;
					len++;
				}
				i = j;
			}
		}
		for (int i = 0; i < v.size(); i++)
			cnt += v[i]/ 2;
		printf("%d", cnt);
	}
	else
		printf("0");
}

void solve3()
{
	vector<node> ans;
	int cnt = 0;
	for (int l = 1; l <= n; l++)
		for (int r = l; r <= n; r++)
			if (getxor(l, r) == k)
				ans.push_back({l, r, r - l + 1});
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		node x = ans[i];
		int l = x.l, r = x.r;
		bool can = true;
		for (int j = l; j <= r; j++)
			if (flg[j])
			{
				can = false;
				break;
			}
		if (can)
		{
			cnt++;
			for (int j = l; j <= r; j++)
				flg[j] = true;
		}
	}
	printf("%d", cnt);
}

bool check1(int v[N]) { for (int i = 1; i <= n; i++) if (v[i] != 1) return false; return true; }
bool check2(int v[N]) { for (int i = 1; i <= n; i++) if (v[i] > 1) return false; return true; }
bool check3(int v[N]) { for (int i = 1; i <= n; i++) if (v[i] > 255) return false; return true; }