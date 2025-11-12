#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+2;j<=n;j++)
		{
			int g=0,h=0;
			for(int k=i;k<=j;k++)
			{
				g+=a[k];
				h=max(h,a[k]);
			}
			if(g>2*h)
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
