#include<bits/stdc++.h>
using namespace std;
long t,n,a[100005][5],f[100005],ff[100005],ma,sum;
void s(int x)
{
	if(x==n)
	{
		ma=max(ma,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(f[i]==0&&ff[j]<=n/2-1)
			{
				sum+=a[i][j];
				f[i]=1;
				ff[j]++;
				s(i+1);
				f[i]=0;
				ff[j]--;
				sum-=a[i][j];
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		int p=0,q=0; 
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		memset(ff,0,sizeof(ff));
		ma=0,sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
				if(j==2&&a[i][j]!=0)
					p=1;
				if(j==3&&a[i][j]!=0)
					q=1;
			}	
		}
		if(p==0&&q==0)
		{
			for(int i=1;i<=n;i++)
			{
				f[i]=a[1][i];
			}
			sort(f+1,f+n+1);
			for(int k=1;k<=n/2;k++)
			{
				ma+=f[k];
			}
			cout<<ma<<endl;
			continue;
		}
		s(1);
		printf("%d\n",ma);
	}
	return 0;
}
