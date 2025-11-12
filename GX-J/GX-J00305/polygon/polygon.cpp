#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int a[5010];
int n,ans=0,maxx=0,k=0,x=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			ans+=a[j];
			for(int p=j+x;p<=n-1;p++)
			{
				ans+=a[p];
				maxx=max(a[p],maxx);
				x++;
			}
			if(ans>maxx*2)
				k++;
			ans=0;
			maxx=0;
			x=0;
		}
	}
	cout<<k;
	return 0;
}

