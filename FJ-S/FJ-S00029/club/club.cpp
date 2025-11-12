#include<bits/stdc++.h>
using namespace std;
int n, t, k, d[1000001], c[4], s;
struct N
{
	int a[4], m, l;
}q[100001];
bool cmp(N x, N y)
{
	return x.m >= y.m;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for(; t--; )
	{
		cin >> n, k = n / 2;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
				cin >> q[i].a[j];
			q[i].l = max(q[i].a[1], max(q[i].a[2], q[i].a[3])), q[i].m = 2 * q[i].l - q[i].a[1] - q[i].a[2] - q[i].a[3];
		}
		sort(q + 1, q + n + 1, cmp), c[1] = c[2] = c[3] = k;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
				if(c[j] <= 0)
					q[i].a[j] = 0;
			q[i].l = max(q[i].a[1], max(q[i].a[2], q[i].a[3]));
			for(int j = 1; j <= 3; j++)
			{
				if(q[i].a[j] == q[i].l)
				{
					c[j]--, s += q[i].l;
					break;
				}
			}
		}
		cout << s << '\n', s = 0;
		
		
	}
	
	
	
	
	
	
	
	return 0;
} 
