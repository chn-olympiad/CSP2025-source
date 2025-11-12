#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm> 
using namespace std;
int t;
bool cmd(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int a[100005] = {}, b[100005] = {}, c[100005] = {}, biggest[100005] = {}, biao[100005] = {};
	int n;
	int num[6] = {}; 
	cin >> t;
	while (t)
	{
		cin >> n;
		for (int i = 0;i < n;i ++)
		{
			cin >> a[i] >> b[i] >> c[i];
		}
		bool y = 1, x = 1;
		for (int i = 0;i < n;i ++)
		{
			if(b[i] != 0)
				y == 0;
			if (c[i] != 0)
				x == 0;
		}
//		cout << x << y;
		if (x && y)
		{
			sort(a, a + n, cmd);
			for (int i = 0;i < n / 2;i ++)
				num[t] += a[i];
		}
		if (x)
		{
			num[t] += max(a[t], b[t]);
		} 
		cout << num[t];
		t--;
	}
	
	//2
	//4 1 0 0 1 0 0 2 0 0 2 0 0
//	int maxa = -1, maxb = -1, maxc = -1;
//	int most = 0;//社团人数有没有超过 
//	for (int i = 0;i < n;i ++)
//	{
//		cin >> a[i] >> b[i] >> c[i];
//		biggest[i] = max(max(a[i], b[i]), c[i]);
//		if (a[i] == biggest[i])
//			biao == 1;
//		else if(a[i] == biggest[i])
//			biao == 2;
//		else
//			biao == 3;
//		if (a[i] > maxa)
//			maxa = a[i];
//		if (b[i] > maxb)
//			baxa = b[i];
//		if (c[i] > maxc)
//			maxc = c[i];
//		//biao为最高满意度的社团的下标 
//		//biggest为该人最高满意度的值 
//	}
//	//1社团
//	int l = n / 2;
//	int ans = 0;
//	
//	for (int i = 0;i < n;i ++)
//	{
//		if (maxa = -1)
//			break;
//		if (num == l)
//			break;
//		if (a[i] == maxa)
//		{
//			ans += a[i];
//			num ++;
//			a[i] = -1; b[i] = [-1];c[i] = -1;
//		}
//	}
//	ans = 0;
//	for (int i = 0;i < n;i ++)
//	{
//		if (maxb = -1)
//			break;
//		if (num == l)
//			break;
//		if (b[i] == maxb)
//		{
//			ans += b[i];
//			num ++;
//			a[i] = -1; b[i] = [-1];c[i] = -1;
//		}
//	}
//	ans = 0;
//	for (int i = 0;i < n;i ++)
//	{
//		if (maxc = -1)
//			break;
//		if (num == l)
//			break;
//		if (c[i] == maxa)
//		{
//			ans += c[i];
//			num ++;
//			a[i] = -1; b[i] = [-1];c[i] = -1;
//		}
//	}

	return 0;
}
