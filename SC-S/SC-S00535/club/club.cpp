//这次运气不好，T1都没拿满
//所以抽昔涟时能不歪吗（doge
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t , n;
struct student
{
	ll happy[4];
}a[100005];
bool cmp1(student p , student q)
{
	if(p.happy[1] == q.happy[1])
	{
		if(p.happy[2] == q.happy[2])
		{
			return p.happy[3] > q.happy[3];
		}
		return p.happy[2] > q.happy[2];
	}
	return p.happy[1] > q.happy[1];
}
bool cmp2(student p , student q)
{
	if(p.happy[2] == q.happy[2])
	{
		if(p.happy[1] == q.happy[1])
		{
			return p.happy[3] > q.happy[3];
		}
		return p.happy[1] > q.happy[1];
	}
	return p.happy[2] > q.happy[2];
}
bool cmp3(student p , student q)
{
	if(p.happy[1] == q.happy[1])
	{
		if(p.happy[3] == q.happy[3])
		{
			return p.happy[2] > q.happy[2];
		}
		return p.happy[3] > q.happy[3];
	}
	return p.happy[1] > q.happy[1];
}
bool cmp4(student p , student q)
{
	if(p.happy[2] == q.happy[2])
	{
		if(p.happy[3] == q.happy[3])
		{
			return p.happy[1] > q.happy[1];
		}
		return p.happy[3] > q.happy[3];
	}
	return p.happy[2] > q.happy[2];
}
bool cmp5(student p , student q)
{
	if(p.happy[3] == q.happy[3])
	{
		if(p.happy[1] == q.happy[1])
		{
			return p.happy[2] > q.happy[2];
		}
		return p.happy[1] > q.happy[1];
	}
	return p.happy[3] > q.happy[3];
}
bool cmp6(student p , student q)
{
	if(p.happy[3] == q.happy[3])
	{
		if(p.happy[2] == q.happy[2])
		{
			return p.happy[1] > q.happy[1];
		}
		return p.happy[2] > q.happy[2];
	}
	return p.happy[3] > q.happy[3];
}
struct club
{
	ll happiness;
	ll sum[4];
}c[100005][3];
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		ll sum1 = 0 , sum2 = 0 , sum3 = 0;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i].happy[1] >> a[i].happy[2] >> a[i].happy[3];
			if(a[i].happy[2] > a[i].happy[1] && a[i].happy[2] > a[i].happy[3])
			{
				sum2++;
			}
			if(a[i].happy[1] > a[i].happy[2] && a[i].happy[1] > a[i].happy[3])
			{
				sum1++;
			}
			if(a[i].happy[3] > a[i].happy[1] && a[i].happy[3] > a[i].happy[2])
			{
				sum3++;
			}
		}
		if(sum1 > sum2 && sum2 > sum3)
		{
			sort(a + 1 , a + n + 1 , cmp1);
		}
		if(sum2 > sum1 && sum1 > sum3)
		{
			sort(a + 1 , a + n + 1 , cmp2);
		}
		if(sum1 > sum3 && sum3 > sum2)
		{
			sort(a + 1 , a + n + 1 , cmp3);
		}
		if(sum2 > sum3 && sum3 > sum1)
		{
			sort(a + 1 , a + n + 1 , cmp4);
		}
		if(sum3 > sum1 && sum1 > sum2)
		{
			sort(a + 1 , a + n + 1 , cmp5);
		}
		if(sum3 > sum2 && sum2 > sum1)
		{
			sort(a + 1 , a + n + 1 , cmp6);
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++)
			{
				for(int k = 1;k <= 3;k++)
				{
					if(c[i - 1][k].happiness > c[i][j].happiness && c[i - 1][k].sum[j] != n / 2)
					{
						c[i][j] = c[i - 1][k];
					}
				}
				c[i][j].happiness += a[i].happy[j];
				c[i][j].sum[j]++;
//				cout << i << ' ' << j << " :" << c[i][j].happiness << ' ';
//				cout << c[i][j].sum[1] << ' ' << c[i][j].sum[2] << ' ' << c[i][j].sum[3] << endl;
			}
		}
		ll ans = 0;
		for(int i = 1;i <= 3;i++)
		{
			ans = max(ans , c[n][i].happiness);
		}
		cout << ans << endl;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++)
			{
				c[i][j].happiness = 0;
				c[i][j].sum[1] = 0;
				c[i][j].sum[2] = 0;
				c[i][j].sum[3] = 0;
			}
			a[i].happy[1] = 0;
			a[i].happy[2] = 0;
			a[i].happy[3] = 0;
		}
	}
	return 0;
}