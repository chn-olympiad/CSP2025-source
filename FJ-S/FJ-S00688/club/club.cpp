#include <bits/stdc++.h>
using namespace std;
struct s
{
	int a1 , b1 , c1; // 对于各组的满意度 
	int n1 , m1 , m2 , h , l; // n1为满意度最高组对于次高组满意度差值 ， m1为最高组 ，m2为次高组 
} a[100020];
bool f(s a , s b)// 按满意度差值降序排列 
{
	return a.n1 > b.n1;
}
bool check(int a , int n)
{
	return a < n / 2;
}
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int T , n;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> a[i].a1 >> a[i].b1 >> a[i].c1;
			if (a[i].a1 > a[i].b1 && a[i].a1 > a[i].c1)
			{
				a[i].m1 = 1;
				a[i].h = a[i].a1;
				if (a[i].b1 > a[i].c1)
				{
					a[i].m2 = 2;
					a[i].l = a[i].b1;
				}
				else
				{
					a[i].m2 = 3;
					a[i].l = a[i].c1;
				}
			}
			if (a[i].b1 > a[i].a1 && a[i].b1 > a[i].c1)
			{
				a[i].m1 = 2;
				a[i].h = a[i].b1;
				if (a[i].a1 > a[i].c1)
				{
					a[i].m2 = 1;
					a[i].l = a[i].a1;
				}
				else
				{
					a[i].m2 = 3;
					a[i].l = a[i].c1;
				}
			}
			if (a[i].c1 > a[i].a1 && a[i].c1 > a[i].b1)
			{
				a[i].m1 = 3;
				a[i].h = a[i].c1;
				if (a[i].b1 > a[i].a1)
				{
					a[i].m2 = 2;
					a[i].l = a[i].b1;
				}
				else
				{
					a[i].m2 = 1;
					a[i].l = a[i].a1;
				}
			}
			a[i].n1 = a[i].h - a[i].l;
		}
		sort (a + 1 , a + n + 1 , f);
		int ans = 0 , r[5] = {0};
		for (int i = 1 ; i <= n ; i++) // n1大的优先处理，同时注意 n/2 条件 
		{
			if (check(r[a[i].m1] , n))
			{
				r[a[i].m1]++;
				ans += a[i].h;
			}
			else
			{
				r[a[i].m2]++;
				ans += a[i].l;
			}
		}
		cout << ans << endl;
	}
	return 0; // t1一定要过啊QAQ 
}
