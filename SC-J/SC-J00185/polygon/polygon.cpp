#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int t=0;
	for(int i=1;i<=n;i++)
	{
		int d=max(a[i],a[i+1]);
		int h=a[i]+a[i+1];
		for(int j=i+2;j<=n;j++)
		{
			int d1=d; 
			d=max(d,a[j]);
			h+=a[j];
			if(d*2<h)
			{
				t++;
			}
			else
			{
				d=d1;
				h-=a[j];
			}
		}
	}
	cout<<t;
	return 0;
}