#include <bits/stdc++.h>
using namespace std;
int a[500005];
int n,k;
void solvea()
{
	if(k==0)cout << n/2;
	else if(k==1)cout << n;
	else cout << 0;
	return;
}
void solveb()
{
	int cnt=0;
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0|(a[i]==1&a[i-1]==1))
			{
				cnt++;
			}
		}
	}
	else if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)cnt++;
		}
	}
	cout << cnt;
	return;
}
int main()
{
	bool fa=1,fb=1;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]>1)fb=0;
		if(a[i]!=1)fa=0;
	}
	if(fa)
	{
		solvea();
		return 0;
	}
	else if(fb)
	{
		solveb();
		return 0;
	}
	else
	{
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(i==k)cnt++;
		}
		cout << cnt;
	}
	return 0;
}
