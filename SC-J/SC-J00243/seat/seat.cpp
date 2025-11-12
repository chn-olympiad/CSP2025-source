#include<bits/stdc++.h>
using namespace std;
int n, m;
int s[110];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int r;
	int nm = n * m;
	for(int i = 1;i <= nm;i++)
	{
		scanf("%d", &s[i]);
	}
	r = s[1];
	sort(s + 1, s + n * m + 1);
	for(int i = 1;i <= (nm >> 1);i++)
	{
		int c = s[i];
		s[i] = s[nm - i + 1];
		s[nm - i + 1] = c;
	}
//	for(int i = 1;i <= nm;i++)
//	{
//		printf("%d ", s[i]);
//	}
	int id = 1;
	for(int i = 1;i <= nm;i++)
	{
		if(s[i] == r)
		{
			id = i;
			break;
		}
	}
	int k = id / n;
	if(k % 2 == 0)
	{
		printf("%d %d", (id - k * n == 0) ? k : k + 1, (id - k * n == 0) ? 1 : id - k * n);
	}
	else
	{
		printf("%d %d", (id - k * n == 0) ? k : k + 1, (id - k * n == 0) ? n : n - (id - k * n) + 1);
	}
	return 0;
}
