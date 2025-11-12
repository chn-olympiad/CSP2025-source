#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("xor.in","R",stdin);
	//freopen("xor.out","W",stdout);
	int n,k,a[100005];
	int am=INT_MIN;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int l=0,r=1;l<n||r<=n;r++)
	{
		int x=r-l+1,add=0;
		for(int i=l;i<r;i++)
		{
			add=add^a[i];
		}
		if(add==k)
		{
			am=max(x,am);
		}
		else if(add>k)
		{
			l++;
		}
	}
	cout<<am/2;	
	return 0;
}
