#include<iostream>
using namespace std;
int a[5005];
int main()
{
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	int s=0,maxn=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(2*maxn>=s)
	{
		cout<<0;
		return 0;
	}
	s=0;
	maxn=-1;
	int ans=0;
	for(int x=1;x<=n;x++)
	{
		for(int y=x;y<=n;y++)
		{
			int an=0;
			for(int i=x;i<=y;i++)
			{
				for(int j=0;j<=1;j++)
				{
					an+=a[i]*j;
					maxn=max(maxn,a[i]*j);
				}
			}
			if(maxn*2<an)
			{
				ans++;
			}
		}
	}
	cout<<ans;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

