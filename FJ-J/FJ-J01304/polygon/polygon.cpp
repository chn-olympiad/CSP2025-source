#include <bits/stdc++.h>
using namespace std;
int n,a[5005],k;
bool flag=1,flag2=0;
int book[5005],top;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]!=1) flag=0;
		if (a[i]<k) flag2=1;
	}
	if (flag2==0)
	{
		cout << 0;
		return 0;
	}
	else if (n==3) 
	{
		sort(a+1,a+n+1);
		if (a[3]>=a[1]+a[2]) cout << 0;
		else cout << 1;
		return 0;
	}
	else if (flag) 
	{
		cout << n*n-n-n*(n-1)/2;
		return 0;
	}
	int count=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]>=k) 
		{
			count++;
			book[++top]=i;
		}
	}
	cout << count;
	return 0;
}	
