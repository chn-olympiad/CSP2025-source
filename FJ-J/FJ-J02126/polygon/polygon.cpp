#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,o=0,p=0,k=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int o=a[i],p=max(p,a[i]);
		for(int j=i+1;j<n;j++)
		{
			if(2*p<o&&j-i>2)
			{
				k++;
			}
			o+=a[j];
			p=max(p,a[j]);
		}
	}
	cout<<k;
	return 0;
 } 
 
