#include <bits/stdc++.h>
using namespace std;
int t,n,a[100002],b[100002],c[100002];
long long ans,f[100002][3];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int ll=1;ll<=t;ll++)
	{
		scanf("%d",&n);
		ans=0;
		bool A=true,B=true;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			f[i][0]=a[i];
			f[i][1]=b[i];
			f[i][2]=c[i];
			if(c[i]!=0)
			{
				A=false;
				B=false;
			}
			if(b[i]!=0)
			{
				A=false;
			}
			if(a[i]>=b[i])
			{
				b[i]=0;
			}
			if(a[i]<b[i])
			{
				a[i]=0;
			}
		}
		if(n==2)
		{
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(i==j)continue;
					ans=max(ans,f[1][i]+f[2][j]);
				}
			}
			cout<<ans<<"\n";
		}
		else if(n==4)
		{
			int d[3]={0,0,0};
			for(int i=0;i<3;i++)
			{
				d[i]++;
				for(int j=0;j<3;j++)
				{
					d[j]++;
					for(int k=0;k<3;k++)
					{
						if(d[k]>=2)continue;
						d[k]++;
						for(int l=0;l<3;l++)
						{
							if(d[l]>=2)continue;
							ans=max(ans,f[1][i]+f[2][j]+f[3][k]+f[4][l]);
						}
						d[k]--;
					}
					d[j]--;
				}
				d[i]--;
			}
			cout<<ans<<"\n";
		}
		else if(A)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		else if(B)
		{
			sort(a+1,a+n+1,cmp);
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans=ans+a[i]+b[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		else 
		{
			for(int i=1;i<=n;i++)
			{
				ans+=max(max(a[i],b[i]),c[i]);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
