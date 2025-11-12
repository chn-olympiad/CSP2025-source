#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a<b;
}
long long n,a[5005],sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
//	cout<<a[1]<<a[2]<<a[3];
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			for(int q = j+1;q<=n;q++)
			{
				if(i+j>q)
				{
					sum++;
				}
			}
		}
	}
	for(int i=1;i<=n-3;i++)
	{
		for(int j=i+1;j<=n-2;j++)
		{
			for(int q = j+1;q<=n-1;q++)
			{
				for(int y =q+1;y<=n;y++)
				{
					if(i+j+q+y>2*y)
					{
						sum++;
					}
				}
			}
		}
	}
//	cout<<sum<<endl;
	for(int r = 1;r<=n-4;r++)
	{
		for(int i=r+1;i<=n-3;i++)
		{
			for(int j=i+1;j<=n-2;j++)
			{
				for(int q = j+1;q<=n-1;q++)
				{
					for(int y =q+1;y<=n;y++)
					{
						if(i+j+q+y+r>2*y)
						{
							sum++;
						}
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
