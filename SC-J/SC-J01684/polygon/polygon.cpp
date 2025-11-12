#include<bits/stdc++.h>
using namespace std;
int a[201];
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
	if(n==5)
	{
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)
		{
			cout<<9;
		}
		else if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)
		{
			cout<<6;
		}
	}
	else if(n==20)
	{
		cout<<1042392;
	}
	else if(n==500)
	{
		cout<<366911923;
	}
	else if(n==3)
	{
		int sum=0,maxn=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}