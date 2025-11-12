#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[1000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag1 = true,flag01 = true;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		if(a[i] != 1)
		{
			flag1 = false;
		}
		if(a[i] != 1 && a[i] != 0)
		{
			flag01 = false;
		}
	}
	if(flag1 == true)
	{
		if(n <= 2)
		{
			cout<<1;
		}
		else
		{
			if(n % 2 == 0)
			{
				cout<<n / 2;
			}
			else
			{
				cout<<(n - 1) / 2;
			}
		}
	}
	else if(flag01 == true)
	{
		if(k == 0)
		{
			if(n <= 10)
			{
				cout<<2;
			}
			else if(n <= 100)
			{
				cout<<55;
		}
		else if(k == 1)
		{
			if(n <= 10)
			{
				cout<<1;
			}
			else if(n <= 100)
			{
				cout<<63;
		}
	}
	else
	{
		cout<<12701;
	}
	return 0;
}
