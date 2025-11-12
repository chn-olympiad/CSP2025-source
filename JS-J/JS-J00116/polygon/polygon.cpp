#include <bits/stdc++.h>
using namespace std;
int n;
long long sum=0,num=0;
int a[50005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if (n<3)
	{
		cout << 0;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	if (sum>a[n]*2)
	{
		num++;
	}
	for (int i=n-1;i>=3;i--)
	{
		for (int j=1;j<=n;i++)
		{
			sum-=a[j];
			if (a[j]!=a[n-1])
			{
				if (sum>a[n-1]*2)
				{
					num++;
				}
			}
			else
			{
				if (sum>a[n-2]*2)
				{
					num++;
				}
			}
		}
	}
	cout << num;
	return 0;
}
