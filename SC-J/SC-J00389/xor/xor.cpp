#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[500005];
struct node
{
	int l, r;
}t[100005];
int s[100005], top;
bool cmp(node a, node b)
{
	if (a.r == b.r)
		return a.l > b.l;
	return a.r < b.r;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], s[i] = s[i - 1] ^ a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if ((s[i] ^ s[j]) == k)
				t[++top] = {j + 1, i};
	for (int i = 1; i <= n; i++)
		if (s[i] == k)
			t[++top] = {1, i};
	sort(t + 1, t + top + 1, cmp);
	int ans = 0;
	int now = 0;
	int i = 1;
	while (i <= top)
	{
		while (t[i].l <= now && i <= top)
			i++;
		if (i > top)
			break;
		ans++, now = t[i].r;
	}
	cout << ans;

	return 0;
}