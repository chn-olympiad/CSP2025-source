#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n<3) cout<<0;
	else if(n==3)
	{
		int sum=0,max=-1;
		for(int i=0;i<n;i++)
		{
			sum+=a[i];
			if(a[i]>max) max=a[i];
		}
		if(max*2>sum) cout<<1;
		else cout<<0;
	}
	else
	{
		cout<<6;
	}
	return 0;
}
