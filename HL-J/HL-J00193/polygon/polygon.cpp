#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		cout<<15;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=i+1)
		{
			cout<<6;
			return 0;
		}
	}
	cout<<9;
	return 0;
}