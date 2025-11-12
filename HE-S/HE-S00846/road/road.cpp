#include <bits/stdc++.h>
using namespace std;
long long n , m , k;
int a[10005][10005] , b[10005][10005] , sum1 = 0 , sum2 = 0;
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		for (int j = 1;j <= 3;j++)
		{
			cin >> a[i][j];
			int minn = min(a[i][j - 1] , a[i][j + 1]);
			sum1 += max(a[i][j] , minn); 
		}
	}
	for (int i = 1;i <= n + 1;i++)
	{
		for (int j = 1;j <= k;j++)
		{
			cin >> b[i][j];
			int maxx = max(b[i][j - 1] , b[i][ j + 1]);
			sum2 += min(b[i][j] , maxx);
		}
	}
	cout << sum1 - sum2 << endl;
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
