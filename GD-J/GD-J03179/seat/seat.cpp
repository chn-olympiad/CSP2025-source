#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, i, j, x;
	cin >> n >> m;
	for(i = 1; i <= n * m; i++)
		cin >> a[i];
	x = a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(i = n+1; i <= n * m; i += n + n)
	{
		reverse(a + i, a + i + n);
	}
	for(i = 1; i <= n * m; i++)
	{
		if(a[i] == x)
		{
			cout << ceil(i / 1.0 / n) << " " << i - (ceil(i / 1.0 / n) - 1) * n;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
