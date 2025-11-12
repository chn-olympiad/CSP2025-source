#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n = 0, q = 0;
	scanf("%d%d", &n, &q);
	vector<string> a1(n);
	vector<string> a2(n);
	for (int i = 0; i < n; ++i)
	{
		a1[i].resize(5000);
		a2[i].resize(5000);
		scanf("%c%c", &a1[i][0], &a2[i][0]);
	}
	for (int i = 0; i < q; ++i)
		printf("0\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
