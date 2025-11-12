#include <bits/stdc++.h>
using namespace std;

struct v
{
	int x,num,id;
	double c;	
};

bool cmp(v x,v y)
{
	return x.c > y.c;
}

bool cmpa(v x,v y)
{
	return x.x > y.x;
}

v a[600015] = {};
int f[200005] = {}; 
int n;

int g()
{
	for(int i = 2;i <= n;i++)
	{
		cin >> a[(i - 1) * 3 + 1].x >> a[(i - 1) * 3 + 2].x >> a[(i - 1) * 3 + 3].x;
	}
	sort(a + 1,a + 3 * n + 1,cmpa);
	int ans = 0;
	for(int i = 1;i <= n / 2;i++)
	{
		ans += a[i].x;
	}
	cout << ans << endl;
	return 0;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	double all1,all2,all3;
	int k1,k2,k3;
	int ans = 0;
	cin >> t;
	for(int o = 1;o <= t;o++)
	{
		all1 = 0;
		all2 = 0;
		all3 = 0;
		k1 = 0;
		k2 = 0;
		k3 = 0;
		cin >> n;
		cin >> a[1].x >> a[2].x >> a[3].x;
		a[1].id = 1;
		a[2].id = 1;
		a[3].id = 1;
		a[1].num = 1;
		a[2].num = 2;
		a[3].num = 3;
		all1 += a[1].x;
		all2 += a[2].x;
		all3 += a[3].x;
		if (a[2].x == 0 && a[3].x == 0)
		{
			g();
			continue;
		}
		memset(f,0,sizeof(f));
		for(int i = 2;i <= n;i++)
		{
			cin >> a[(i - 1) * 3 + 1].x >> a[(i - 1) * 3 + 2].x >> a[(i - 1) * 3 + 3].x;
			a[(i - 1) * 3 + 1].id = i;
			a[(i - 1) * 3 + 2].id = i;
			a[(i - 1) * 3 + 3].id = i;
			a[(i - 1) * 3 + 1].num = 1;
			a[(i - 1) * 3 + 2].num = 2;
			a[(i - 1) * 3 + 3].num = 3;
			all1 += a[(i - 1) * 3 + 1].x;
			all2 += a[(i - 1) * 3 + 2].x;
			all3 += a[(i - 1) * 3 + 3].x;
		}
		for(int i = 1;i <= 3 * n;i++)
		{
			if (a[i].num == 1)
			{
				a[i].c = a[i].x / all1;
			}
			if (a[i].num == 2)
			{
				a[i].c = a[i].x / all2;
			}
			if (a[i].num == 3)
			{
				a[i].c = a[i].x / all3;
			}
		}
		sort(a + 1,a + 3 * n + 1,cmp);
		ans = 0;
		for(int i = 1;i <= 3 * n;i++)
		{
			if (a[i].num == 1)
			{
				if (k1 < n / 2 && f[a[i].id] == 0)
				{
					k1++;
					f[a[i].id] = 1;
					ans += a[i].x;
				}
			}
			if (a[i].num == 2 && f[a[i].id] == 0)
			{
				if (k2 < n / 2)
				{
					k2++;
					f[a[i].id] = 2;
					ans += a[i].x;
				}
			}
			if (a[i].num == 3 && f[a[i].id] == 0)
			{
				if (k3 < n / 2)
				{
					k3++;
					f[a[i].id] = 3;
					ans += a[i].x;
				}
			}
		}
//		for(int i = 1;i <= n;i++)
//		{
//			cout << f[i] << " ";
//		}
//		cout << endl;
		cout << ans << endl;
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
/*
18
4
13
*/
