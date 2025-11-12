#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n,a[5001],o=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int Max=-1,x=0,l=0;
		for(int j=i;j<n;j++)
		{
			Max=max(a[j],Max);
			x++;
			l+=a[j];
			if(x>=3&&l>2*Max)
			{
				o++;
			}
		}
	} 
	cout<<o;
	return 0;
}
