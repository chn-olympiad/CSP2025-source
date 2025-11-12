#include <bits/stdc++.h>
using namespace std;

struct st
{
	long long num, id;
};

long long n, m;
st a[105];

bool cmp(st x, st y)
{
	return x.num > y.num;
}


int main()
{
	#ifdef LOCAL
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	#endif
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++)
	{
		cin >> a[i].num;	
		a[i].id = i;
	} 
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i ++)
	{
		if(a[i].id == 1)
		{
			long long h = 0, l = 0;
			l = (i - 1) / n + 1;
			if(l % 2 == 0)
			{
				if(i % n == 0)
				{
					h = 1;
				}
				else
				{
					h = n - i % n + 1;
				}
			}
			else
			{
				if(i % n == 0)
				{
					h = n;
				}
				else
				{
					h = i % n;
				}
			}
			cout << l << " " << h << endl;
			break;
		}	
	} 
	return 0;
}
