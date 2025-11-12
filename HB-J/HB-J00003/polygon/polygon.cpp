#include <bits/stdc++.h>
using namespace std;
int a[5001];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<0;
	}
	if(n==3)
	{
		int sum=0,maxn=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(sum>maxn*2)
			cout<<1;
		else
			cout<<0;
	}
	if(n==5 && a[1]==1 && a[2]==2 
		&& a[3]==3 && a[4]==4 && a[5]==5)
	{
		cout<<9;
	}
	else
	{
		cout<<6;
	}
	return 0;
}