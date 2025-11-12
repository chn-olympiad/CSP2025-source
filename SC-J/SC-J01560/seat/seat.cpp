#include <iostream>
#include <algorithm>
using namespace std;
int a[120];
int main()
{
	int n,m;
	cin>>n>>m;
	int k=n*m-1;
	int t;
	cin>>t;
	for (int i=1;i<=k;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+k+1);
	int l=1,r=k;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (a[mid]<t)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	 
	int s=n*m+1-l;
	int cur=0;
	for (int i=1;i<=m;i++)
	{
		if (i%2==1)
		{
			for (int j=1;j<=n;j++)
			{
				cur++;
				if (cur==s)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for (int j=n;j>=1;j--)
			{
				cur++;
				if (cur==s)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
