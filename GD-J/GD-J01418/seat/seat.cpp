#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m;
struct num{
	int ind, val;
}a[N];
bool cmp(num x, num y)
{
	if(x.val == y.val) return x.ind < y.ind;
	return x.val > y.val;
}
int cnt = 0;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++)
	{
		cin >> a[i].val;
		a[i].ind = i;
	}
	sort(a+1, a+1+n*m, cmp);
	int loc;
	for(int i = 1; i <= n*m; i++)
	{
		if(a[i].ind == 1)
		{
			loc = i;
			break;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		bool fl = 0;
		if(i % 2 == 0)
		{
			for(int j = n; j >= 1; j--)
			{
				cnt++;
				if(cnt == loc)
				{
					cout << i << " " << j;
					fl = 1;
					break;
				}
			}
		}
		else
		{
			for(int j = 1; j <= n; j++)
			{
				cnt++;
				if(cnt == loc)
				{
					cout << i << " " << j;
					fl = 1;
					break;
				}
			}
		}
		if(fl) break;
	}
	return 0;
}
