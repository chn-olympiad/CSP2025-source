#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
int a[N], n, k, cnt, t, cur, en; 

struct node
{
	int s, e;
} b[N];

bool cmp(node x, node y)
{
	return x.e < y.e;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			t = a[i];
			for (int l = i + 1; l <= j; l++) t ^= a[l];
			if (t == k) cur++, b[cur].s = i, b[cur].e = j;
		}
	}
	sort(b + 1, b + cur + 1, cmp);
	en = b[1].e;
	for (int i = 1; i <= cur; i++)
		if (b[i].s > en)
			en = b[i].e, cnt++;
	cout << cnt + 1	;
	return 0; 
}
