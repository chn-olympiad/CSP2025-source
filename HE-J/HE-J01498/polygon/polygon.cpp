#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >>n;
	if (n<3)
	{
		cout <<0;
		return 0;
	}
	int a[n+1];
	cin >>a[1];
	int max=a[1];
	long long ans=0,num=0;
	num+=a[1];
	for (int i=2;i<=n;i++)
	{
		cin >>a[i];
		num+=a[i];
		if (a[i]>a[1])
		{
			max=a[i];
		}
	}
	if (num>max*2)
	{
		ans++;
	}
	cout <<ans;
	return 0;
}
