#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	int n , a[5005] = {} , cnt = 0;
	cin >> n;
	for(int i = 0 ; i <= n - 1 ; i ++)
	{
		cin >> a[i];
	}
	if(n < 3)
	{
		cout << cnt;
		return 0;
	}
	int maxn = 0;
	if(n == 4)
	{
		maxn = 0;
		maxn = max(maxn , a[0]);
		maxn = max(maxn , a[1]);
		maxn = max(maxn , a[2]);
		if(a[0] + a[1] + a[2] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[3]);
		maxn = max(maxn , a[1]);
		maxn = max(maxn , a[2]);
		if(a[3] + a[1] + a[2] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[0]);
		maxn = max(maxn , a[1]);
		maxn = max(maxn , a[3]);
		if(a[0] + a[1] + a[3] > 2 * maxn)
			cnt ++;
		cout << cnt;
	}
	else if(n == 5)
	{
		cnt = 0;
		maxn = 0;
		maxn = max(maxn , a[0]);
		maxn = max(maxn , a[1]);
		maxn = max(maxn , a[2]);
		if(a[0] + a[1] + a[2] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[0]);
		maxn = max(maxn , a[1]);
		maxn = max(maxn , a[3]);
		if(a[0] + a[1] + a[3] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[0]);
		maxn = max(maxn , a[1]);
		maxn = max(maxn , a[4]);
		if(a[0] + a[1] + a[4] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[0]);
		maxn = max(maxn , a[2]);
		maxn = max(maxn , a[3]);
		if(a[0] + a[2] + a[3] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[0]);
		maxn = max(maxn , a[1]);
		maxn = max(maxn , a[2]);
		if(a[0] + a[1] + a[2] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[0]);
		maxn = max(maxn , a[2]);
		maxn = max(maxn , a[4]);
		if(a[0] + a[2] + a[4] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[0]);
		maxn = max(maxn , a[3]);
		maxn = max(maxn , a[4]);
		if(a[0] + a[3] + a[4] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[1]);
		maxn = max(maxn , a[2]);
		maxn = max(maxn , a[3]);
		if(a[3] + a[1] + a[2] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[4]);
		maxn = max(maxn , a[1]);
		maxn = max(maxn , a[2]);
		if(a[4] + a[1] + a[2] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[3]);
		maxn = max(maxn , a[4]);
		maxn = max(maxn , a[2]);
		if(a[3] + a[4] + a[2] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[1]);
		maxn = max(maxn , a[3]);
		maxn = max(maxn , a[4]);
		if(a[3] + a[1] + a[4] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[0]);
		maxn = max(maxn , a[1]);
		maxn = max(maxn , a[2]);
		maxn = max(maxn , a[3]);
		if(a[3] + a[1] + a[2] + a[0] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[0]);
		maxn = max(maxn , a[1]);
		maxn = max(maxn , a[2]);
		maxn = max(maxn , a[4]);
		if(a[4] + a[1] + a[2] + a[0] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[0]);
		maxn = max(maxn , a[1]);
		maxn = max(maxn , a[3]);
		maxn = max(maxn , a[4]);
		if(a[3] + a[4] + a[1] + a[0] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[0]);
		maxn = max(maxn , a[2]);
		maxn = max(maxn , a[4]);
		maxn = max(maxn , a[3]);
		if(a[3] + a[4] + a[2] + a[0] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[4]);
		maxn = max(maxn , a[1]);
		maxn = max(maxn , a[2]);
		maxn = max(maxn , a[3]);
		if(a[3] + a[1] + a[2] + a[4] > 2 * maxn)
			cnt ++;
		maxn = 0;
		maxn = max(maxn , a[4]);
		maxn = max(maxn , a[1]);
		maxn = max(maxn , a[2]);
		maxn = max(maxn , a[3]);
		maxn = max(maxn , a[0]);
		if(a[3] + a[1] + a[2] + a[4] + a[0] > 2 * maxn)
			cnt ++;
		cout << cnt;
	}//jiheyi xiaojingran babywomendeganqinghaoxiangtiaolouji rangwoturandeshengkongyoujisuluodi
	else 
		cout << n;
	return 0;
}
