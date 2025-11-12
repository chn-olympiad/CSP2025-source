#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int n,m;
int num;
int a[1000005],aa;
int ans1,ans2;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	aa=n*m+1;
	for(int i=1;i<=n*m;i++)
	{
			cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				aa--;
				if(a[aa]==num)
				{
					ans1=i;
					ans2=j;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				aa--;
				if(a[aa]==num)
				{
					ans1=i;
					ans2=j;
				}
			}
		}
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}