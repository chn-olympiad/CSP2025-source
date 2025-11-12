#include<bits/stdc++.h>
using namespace std;
int t,n,ans,x1=0,x2=0,x3=0;
void init()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[100000][4],b=0,ans=0,x,vis[100000];
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
		 } 
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++)
		{
			b=0;
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=3;k++)
				{
					if(k==1)
					{
						if(vis[j]==0&&a[j][k]>b&&x1<=n/2+4)
						{
							b=a[j][k];
							x=j;
							x1++;
						}
					}
					if(k==2)
					{
						if(vis[j]==0&&a[j][k]>b&&x2<=n/2+4)
						{
							b=a[j][k];
							x=j;
							x2++;
						}
					}
					if(k==3)
					{
						if(vis[j]==0&&a[j][k]>b&&x3<=n/2+4)
						{
							b=a[j][k];
							x=j;
							x3++;
						}
					}
				}
			}
			ans+=b;
			vis[x]=1;
		}
		cout<<ans<<endl;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	init();
	return 0;
 } 
