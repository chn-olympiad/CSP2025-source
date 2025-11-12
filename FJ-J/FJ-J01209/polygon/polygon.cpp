#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],b[5005],sum=0,num=0;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n-2;i++)
	{
		sum = a[i]+a[i-1];
		for(int j = i+2;j <= n;j++)
		{
			sum += a[j];
			if(sum > a[j]*2)
			{
				num++;	
			}
		}
	}
	cout << num;
	return 0;
}
