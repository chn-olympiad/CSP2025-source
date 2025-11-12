#include <iostream>
int sum[5010];
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010],max = -1,num = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
		if (max < a[i])
		{
			max = a[i];
		}
	}
	for (int i = 3;i <= n+2;i++)
	{
		if (sum[i] > max)
		{
			num++;
		}
	}
	cout << num;
} 
