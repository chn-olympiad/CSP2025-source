#include <cstdio>
#include <algorithm>
struct T
{
	int score, id;
} a[101];
bool f(T v, T w)
{
	return v.score > w.score;
}
using namespace std;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i ++)
	{
		scanf("%d", &(a[i].score));
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, f);
	for (int i = 1; i <= n * m; i ++)
	{
		if (a[i].id == 1)
		{
			if (((i / n + 1 - !(bool(i % n)))) % 2 == 0)
			{
				printf("%d %d", 
				i / n + 1 - !(bool(i % n)), 
				n - i % m + m * !((bool)(i % m)) + 1);
			}
			else
			{
				printf("%d %d", 
				i / n + 1 - !(bool(i % n)), 
				i % m + m * !((bool)(i % m)));
			}
			return 0;
		}
	}
	return 0;
}
