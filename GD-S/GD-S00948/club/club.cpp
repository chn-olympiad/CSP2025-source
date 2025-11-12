#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stdio.h>
#include<queue>
using namespace std;

struct as {
	int a1, a2, a3;
};

bool cmp1(as x, as y)
{
	if(x.a1 == 0 || y.a1 == 0)
	{
		if(x.a1 == 0 && y.a1 == 0)
			return max(x.a2, x.a3) < max(y.a2, y.a3);
		else return x.a1 > y.a1;
	}
	else if(x.a1 != 0 && y.a1 != 0)
		return max(x.a2, x.a3) > max(y.a2, y.a3);
}

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		as a[n + 5] = {};
		int ans = 0;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		int max1 = 0, max2 = 0, max3 = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			if(a[i].a1 >= a[i].a2 && a[i].a1 >= a[i].a3) 
				max1++;
			else if(a[i].a2 >= a[i].a1 && a[i].a2 >= a[i].a3)
				max2++;
			else if(a[i].a3 >= a[i].a1 && a[i].a3 >= a[i].a2)
				max3++;
		}
		for(int i = 1; i <= n; i++)
		{
			int maxx = max(a[i].a1, max(a[i].a2, a[i].a3));
			ans += maxx;
			a[i].a1 -= maxx;
			a[i].a2 -= maxx;
			a[i].a3 -= maxx;
		}
		if(max1 <= n / 2 && max2 <= n / 2 && max3 <= n / 2)
		{
			cout << ans << endl;
			continue;
		}
		if(max2 > n / 2)
		{
			for(int i = 1; i <= n; i++)
			{
				swap(a[i].a2, a[i].a1);
			}
		}
		else if(max3 > n / 2)
		{
			for(int i = 1; i <= n; i++)
			{
				swap(a[i].a3, a[i].a1);
			}
		}
		sort(a + 1, a + n + 1, cmp1);
		for(int i = n / 2 + 1; i <= n; i++)
			ans += max(a[i].a2, a[i].a3);
		cout << ans << endl;
		continue;
	}
	return 0;
}
