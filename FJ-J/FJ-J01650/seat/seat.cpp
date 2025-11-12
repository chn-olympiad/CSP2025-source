#include <bits/stdc++.h>
using namespace std;
int a[100000];
int cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int s = n * m;
	for (int i = 1 ; i <= s ; i++)
	{
		cin >> a[i];
	}
	int num = a[1];
	int sum = 1;
	sort(a + 1,a + s + 1,cmp);
	for (int i = 1 ; i <= m ; i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				if(a[sum] == num)
				{
					cout << i << " " << j;
					return 0;
				}
				sum++;
			}
		}
		else
		{
			for(int j = n ; j >= 1 ; j--)
			{
				if(a[sum] == num)
				{
					cout << i << " " << j;
					return 0;
				}
				sum++;
			}
		}
	}
	return 0;
}
