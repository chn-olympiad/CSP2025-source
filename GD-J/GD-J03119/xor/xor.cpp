#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N], xors[N], ans, n, k;
void dfs(int l, int cnt)
{
	bool found = false;
	for (int i = l; i <= n; i++)
		for (int j = i; j <= n; j++)
		{
			if ((xors[j] ^ xors[i - 1]) == k)
			{
				dfs(j + 1, cnt + 1);
				found = true;
			}
		 } 
	if (!found) ans = max(ans, cnt);
 } 
int solve()
{
	memset(a, 0, sizeof a);
	memset(xors, 0, sizeof xors);
	int cnt1 = 0; scanf("%d %d", &n, &k);
	bool A = 1, B = 1, C = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		xors[i] = xors[i-1] ^ a[i];
		if (a[i] == 1) cnt1++; 
		if (a[i] != 1 or k == 1) A = false;
		if (a[i] > 1 or k > 1) B = false;
		if (a[i] > 225) C = false;
	} 
	if (A)//Ãÿ ‚–‘÷ A
	{
		printf("%d", n / 2);	
		return 0;
	}
	if (B)
	{
		if (k == 0)
		{
			printf("%d", cnt1 / 2);
			return 0;
		}
		if (k == 1)
		{
			printf("%d", cnt1);
			return 0;
		}
	}
	ans = 0;
	dfs(1, 0);
	printf("%d", ans); 
	return 0;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

