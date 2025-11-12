#include <bits/stdc++.h>
using namespace std;
int n, m;
int s, p, maxn = 0;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			if(i == 1 && j == 1) continue;
			scanf("%d", &p);
			if(p>s) maxn++;
		}
	}
	int c = maxn/m+1,//前面填满的列数+1 
		r = ((maxn/m+1)%2==0?n-(maxn%m) : maxn%m+1);
		//两种情况	1.如果列数为奇(从1开始)则是当前列前面的人+1(即maxn%m+1) 
		//			2.如果列数为偶(从1开始)则是行数-当前列前面的人(即n-(maxn%m)) 
	cout << c << " " << r;
	return 0;
}

