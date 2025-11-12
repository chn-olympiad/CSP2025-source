#include <iostream>
#include <algorithm>
using namespace std;

const int N = 105;

struct Node
{
	int v, id;
} a[N];

int n, m, xrp;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	int nm = n * m;
	for (int i = 1; i <= nm; ++ i)
	{
		scanf("%d", &a[i].v);
		a[i].id = i;
	}
	
	sort(a + 1, a + nm + 1, [&](const Node &x, const Node &y)
	{
		if (x.v == y.v)
		{
			return x.id < y.id;
		}
		return x.v > y.v;
	});
	
	for (int i = 1; i <= nm; ++ i)
	{
		if (a[i].id == 1)
		{
			int row = i % n, 
				col = i / n;
			
			if (!row)
			{
				row = n;
			}
			if ((double)i / n != col)
			{
				++ col;
			}
			
			if (!(col & 1))
			{
				row = n + 1- row;
			}
			
			printf("%d %d\n", col, row);
			return 0;
		}
	}
}
