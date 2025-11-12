#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5003];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	else if(n==3)
	{
		int num=0;
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			num+=a[i];
			maxn=(maxn,a[i]);
		}
		if(num>maxn*2)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	return 0;
}
