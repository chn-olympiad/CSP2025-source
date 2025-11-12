#include<bits/stdc++.h>
using namespace std;
long long a,b,cnt,head[1000005],c,n,m,d,h,l,f[1005][1005],ans,lp[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>a>>b>>c;
	for(int i=1;i<=b;i++)
	{
		cin>>n>>m>>l;
		if(f[n][m]==0)
		f[n][m]=f[m][n]=9999999999999;
		f[n][m]=min(f[n][m],l);
		f[m][n]=min(f[m][n],l);
	}
	for(int i=1;i<=c;i++)
	{
		cin>>n;
		for(int j=1;j<=a;j++)
		{
			cin>>head[j];
		}
		for(int j=1;j<=a;j++)
		{
			for(int k=1;k<=a;k++)
			{
				if(j!=k)
				{
					if(f[j][k]==0)
					{
						f[j][k]=f[k][j]=9999999999999;
					}
					f[k][j]=min(f[k][j],n+head[k]+head[j]);
		f[j][k]=min(f[j][k],n+head[k]+head[j]);
				}
			}
		}
	}
	
	long long root=1,mn=a;
	lp[root]=1;
	mn--;
	while(mn--)
	{
		long long po=9999999999999,lo=0;
		for(int i=1;i<=a;i++)
		{	
			if(lp[i]==0&&f[i][root]<po)
			{
				lo=i;
				po=f[i][root];
			
			}
		}
		ans+=f[lo][root];
		lp[lo]=1;
		root=lo;
	}
	cout<<ans; 
	return 0;
}
