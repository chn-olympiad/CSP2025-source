#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//给定小R所在的考场座位的行数n与列数m  输出一行两个正整数c,r表示小R的座位为第c列第r行
	int n,m,c,r,s;
	cin >>n >> m >> c >> r >> s;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[N];
		if (a[N] > 0 && s<a[N])
		{
			cout << s;
		}
		else
		{
			if (s>a[N])
			{
				cout << n*m;//jy
			}
		}
	}
	
	
	return 0;
}
