#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[110];
int stu[20][20];
bool cmp(int a, int b)
{
	return a > b;
}
int goal, x = 0, y = 0;
int tmp = 1;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++)
		scanf("%d",&a[i]);
	goal = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1; i <= n; i++)
		if(i % 2 == 0)
			for(int j = m; j >= 1; j--)
				stu[i][j] = a[tmp++];
		else
			for(int j = 1; j <= m; j++)
				stu[i][j] = a[tmp++];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(stu[i][j] == goal)
				x = i, y = j;
	printf("%d %d", x, y);
	return 0;
}
