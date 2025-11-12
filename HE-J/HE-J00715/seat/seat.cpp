#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct se
{
	int id,s;
}a[110];
bool cmp(se x,se y)
{
	return x.s > y.s;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++)
	{
		cin >> a[i].s;
		a[i].id = i;
	}
	sort(a + 1, a + 1 + n * m,cmp);
	int c = 0,h = 1,l = 1;
	bool f = 0;
	while(c != 1)
	{
		while(h <= n)
		{
			c = a[(l - 1) * n + h].id;
			if(c == 1)
			{
				f = 1;
			}
			if(f)
			{
				cout << l << ' ' << h << '\n';
				return 0;
			}
			h ++;
		}
		h --;
		l ++;
		while(h >= 1)
		{
			c = a[l * n - h + 1].id;
			if(c == 1)
			{
				f = 1;
			}
			if(f)
			{
				cout << l << ' ' << h << '\n';
				return 0;
			}
			h --;
		}
		h ++;
		l ++;
	}
	return 0;
}
