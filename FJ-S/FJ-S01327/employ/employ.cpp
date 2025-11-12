#include <bits/stdc++.h>
using namespace std;

const int N = 508;
char s[N];
int a[N];
int p[N];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	iota(p + 1, p + 1 + n, 1);
	int ans = 0;
	do
	{
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			if(s[i] == '0' || cnt >= a[p[i]])
				cnt++;
		if(n - cnt >= m)
			ans++;
	} while(next_permutation(p + 1, p + 1 + n));
	printf("%d\n", ans);
	return 0;
}