#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],k=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		k+=a[i];
	}
	if(n==3)
	{
		int ax=0;
		for(int i=1;i<=3;i++)
		{
			if(ax<a[i]) ax=a[i];
		}
		if(k>2*ax)
		{
			cout<<1;	
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(k==n)
	{
		cout<<((n-1)*(n-2))/2;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}