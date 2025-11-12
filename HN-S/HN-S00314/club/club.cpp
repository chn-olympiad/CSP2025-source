#include<bits/stdc++.h>
using namespace std;
int a[100005][10]={0};
int s[100000]={0};
int m[1000]={0};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int n;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		int d=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>=m[i])
				{
					m[i]=a[i][j];
				}
			}	
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=m[i];
		}
		cout<<ans;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
