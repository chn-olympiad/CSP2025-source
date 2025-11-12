#include<bits/stdc++.h>
using namespace std;
int a[5006];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		for(int i=1;i<=n-2;i++)
		{
			for(int j=i+1;j<=n-1;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if((a[i]+a[j])>a[k])
					{
						cnt++;
					}
				}
			}
		}
	}
	cout<<cnt;
}
