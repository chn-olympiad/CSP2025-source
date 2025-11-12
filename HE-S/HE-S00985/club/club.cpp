#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t1,n,q;
	cin>>t1;
	q=t1;
	int yucun[t1++]={},manyi[4][100001]={0},a[100001],b[4]={};
	int e[100000],d[10001];
	for(int i=1;i<=t1-1;i++)
	{
		cin>>n;
		for(int t=1;t<=n;t++)
		{
			cin>>manyi[1][t]>>manyi[2][t]>>manyi[3][t];
		}
		for(int t=1;t<=n;t++)
		{
			
			if(manyi[1][t]>=manyi[2][t])
			{
				a[t]=manyi[1][t];
				b[1]++;
				d[t]=1;
			}
			if(manyi[2][t]>manyi[1][t])
			{
				a[t]=manyi[2][t];
				b[2]++;
				d[t]=2;
			}
			if(a[t]<=manyi[3][t])
			{
				a[t]=manyi[3][t];
				b[3]++;
				d[t]=3;
			}			
			if(b[1]>n/2+1)
			{
				for(int u=1;u<=t;u++)
				{
					if(d[u]==1&&a[u]<e)
					{
						e=u;
					}
				}
				if(manyi[2][e]>manyi[3][e])
				{
					a[e]=manyi[2][e];
					b[2]++;
					d[e]=2;
				}
				else
				{
					a[e]=manyi[3][e];
					b[3]++;
					d[e]=3;
				}
			}
		
			if(b[2]>n/2+1)
			{
				for(int u=1;u<=t;u++)
				{
					if(d[u]==2&&a[u]<e)
					{
						e=u;
					}
				}
				if(manyi[1][e]>manyi[3][e])
				{
					a[e]=manyi[1][e];
					b[1]++;
					d[e]=1;
				}
				else
				{
					a[e]=manyi[3][e];
					b[3]++;
					d[e]=3;
				}
			}
			
			if(b[3]>n/2+1)
			{
				for(int u=1;u<=t;u++)
				{
					if(d[u]==3&&a[u]<e)
					{
						e=u;
					}
				}
				if(manyi[2][e]>manyi[1][e])
				{
					a[e]=manyi[2][e];
					b[2]++;
					d[e]=2;
				}
				else
				{
					a[e]=manyi[1][e];
					b[1]++;
					d[e]=3;
				}
			}
			
		}
		for(int t=1;t<=n;t++)
		{
			yucun[i]=yucun[i]+a[t];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<yucun[i]<<endl;
	}
	return 0;
}
