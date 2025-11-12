#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int sum=1;
	for(int i=2;i<=n*m;i++)
	{
		if(a[i]>a[1])
		{
			sum++;
		}
	}
	int hs,ls;
	if(sum%n==0)
	{
		ls=sum/n;
		if(ls%2==0)
		{
			hs=1;
		}
		else
		{
			hs=n;
		}
	}
	else
	{
		ls=sum/n+1;
		if(ls%2==0)
		{
			hs=n-(sum%n)+1;
		}
		else
		{
			hs=sum%n;
		}
	}
	cout<<ls<<" "<<hs;
	return 0;
	fclose(stdin);
	fclose(stdout);
}