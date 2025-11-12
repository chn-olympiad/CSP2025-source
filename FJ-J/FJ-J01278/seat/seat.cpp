#include<bits/stdc++.h>
using namespace std;
int n, m, s, f;
struct cnm{
	int x, y;
}a[150];
int cmp(cnm a, cnm b)
{
	return a.x > b.x;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	a[1].y = 1;
	for(int i = 1; i <= n * m; i++) scanf("%d", &a[i].x);
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++) if(a[i].y) s = i;
	int i = 1, j = 1;
	s--;
	while(s--)
	{
		if(!f)
		{
			if(j == n) f = 1, i++;
			else j++;
		}
		else
		{
			if(j == 1) f = 0, i++;
			else j--;
		}
	}
	cout << i << ' ' << j;
	return 0;
}

