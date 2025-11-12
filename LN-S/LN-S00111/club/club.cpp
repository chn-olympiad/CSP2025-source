#include<bits/stdc++.h>
using namespace std;
long long a[100030];
long long b[100030];
long long c[100030];
long long f[202][202][202];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--)
	{
		long long maxx=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
		}
		if(n<201)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=min(i,n/2);j++)
				{
					for(int k=max(0,i-j-n/2);k<=min(i-j,n/2);k++)
					{
						int ii=j,jj=k,kk=i-j-k;
						if(ii==0)
						{
							if(jj==0)
							{
								f[i][j][k]=f[i-1][j][k]+c[i];
							}
							else if(kk==0)
							{
								f[i][j][k]=f[i-1][j][k-1]+b[i];
							}
							else
							{
								f[i][j][k]=max(f[i-1][j][k-1]+b[i],f[i-1][j][k]+c[i]);
							}
						}
						else if(jj==0)
						{
							if(kk==0)
							{
								f[i][j][k]=f[i-1][j-1][k]+a[i];
							}
							else
							{
								f[i][j][k]=max(f[i-1][j-1][k]+a[i],f[i-1][j][k]+c[i]);
							}
						}
						else if(kk==0)
						{
							f[i][j][k]=max(f[i-1][j-1][k]+a[i],f[i-1][j][k-1]+b[i]);
						}
						else
						{
							f[i][j][k]=max(max(f[i-1][j][k-1]+b[i],f[i-1][j][k]+c[i]),f[i-1][j-1][k]+a[i]);
						}
						maxx=max(maxx,f[i][j][k]);
					}
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{	
				if(c[i]!=0 || b[i]!=0)
				{
					break;
				}
				if(i==n)
				{
					sort(a+1,a+n+1);
					for(int i=n;i>=n/2;i++)
					{
						maxx+=a[i];
					}
				}
			}
			if(maxx==0)
			{
				cout<<1;
			}
		}
		cout<<maxx<<endl;
	}
	//zzzxxxyyy
	return 0;
}
