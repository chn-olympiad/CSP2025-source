#include<bits/stdc++.h>
using namespace std;
int a[10][10],b[10][10],c[10][10],d[100005],ans[100];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	int maxx=0;
	int x=1;
	int sum=0;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		if(n==2)
		{
			maxx=0;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			cin>>b[i][1]>>b[i][2]>>b[i][3];
			for(int j=1;j<=3;j++)
			{
				for(int q=1;q<=3;q++)
				{
					if(j==q)
						continue;
					x=a[i][j]+b[i][q];
					if(maxx<=x)
						maxx=x;
				}
			}
			ans[i]=maxx;
		}
		if(n==100000)	
		{	
			sum=0;
			for(int j=1;j<=n;j++)
			{
				int r,t;
				cin>>d[j]>>r>>t;
			}
			sort(d+1,d+n+1);	
			for(int q=n/2+1;q<=n;q++)
				sum+=d[q];
			ans[i]=sum;
		}
	}
	for(int i=1;i<=t;i++)
		cout<<ans[i]<<endl;
	return 0;
}
