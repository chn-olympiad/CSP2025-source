#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][5],b[5][100010],d[100010];
long long sum;
int main()
{
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		int k1=0,k2=0,k3=0;
		sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>a[i][2])
			{
				if(a[i][1]>a[i][3])
				{
					b[1][++k1]=i;sum+=a[i][1];
				}
				else
				{
					b[3][++k3]=i;sum+=a[i][3];
				}
			}
			else
			{
				if(a[i][2]>a[i][3])
				{
					b[2][++k2]=i;sum+=a[i][2];
				}
				else
				{
					b[3][++k3]=i;sum+=a[i][3];
				}
			}
		}
		int v=0;
		long long sum2=0;
		if(k1>n/2)
		{
			for(int i=1;i<=k1;i++)
			{
				d[++v]=min(a[b[1][i]][1]-a[b[1][i]][2],a[b[1][i]][1]-a[b[1][i]][3]);
			}
			sort(d+1,d+k1+1);
			for(int i=1;i<=k1-(n/2);i++)	sum2+=d[i];
		}
		else if(k2>n/2)
		{
			for(int i=1;i<=k2;i++)
			{
				d[++v]=min(a[b[2][i]][2]-a[b[2][i]][1],a[b[2][i]][2]-a[b[2][i]][3]);
			}
			sort(d+1,d+k2+1);
			for(int i=1;i<=k2-(n/2);i++)	sum2+=d[i];
		}
		else if(k3>n/2)
		{
			for(int i=1;i<=k3;i++)
			{
				d[++v]=min(a[b[3][i]][3]-a[b[3][i]][1],a[b[3][i]][3]-a[b[3][i]][2]);
			}
			sort(d+1,d+k3+1);
			for(int i=1;i<=k3-(n/2);i++)	sum2+=d[i];
		}
		cout<<sum-sum2<<"\n";
	}
	return 0;
 } 
