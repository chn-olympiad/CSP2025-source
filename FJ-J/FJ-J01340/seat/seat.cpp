#include <bits/stdc++.h>
using namespace std;
long long n,m,a,b;
struct T
{
	int bh,cj;
}t[105];
bool cmp(T x,T y)
{
	return x.cj > y.cj;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> t[i].cj;
		t[i].bh = i;
	}
	sort(t + 1,t + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i++)
	{
		if(t[i].bh == 1)
		{
			b = ceil(i * 1.0 / n);
			if(b % 2 == 1)
			{
				if(i % n == 0)
				{
					a = n;
				}
				else
				{
					a = i % n;
				}
			}
			else
			{
				if(i % n == 0)
				{
					a = 1;
				}
				else
				{
					a = n - i % n + 1;
				}
			}
			cout << b << " " << a;
			return 0;
		}
	}
	return 0;
}
