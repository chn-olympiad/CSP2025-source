#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[30],m=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i]+a[j+1]+a[j+2]>max(a[i],a[j+2]))
			{
				m++;
			}
		}
	}
	cout<<m;
	return 0;
}
