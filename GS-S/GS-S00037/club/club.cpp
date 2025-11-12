#include<bits/stdc++.h>
using namespace std;
int tt,f2=0,f3=0,f1=0;
long long int n,kk,ans=0,pp=0,m1[200010],m2[200010],m3[200010];
map <int,int> mp1;
map <int,int> mp2;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&tt);
	for(int mm=0;mm<tt;mm++)
	{
		scanf("%lld",&n);
		kk=n/2;
		f1=0;
		f2=0;
		f3=0;
		pp=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&m1[i],&m2[i],&m3[i]);
			mp1[i]=m1[i];
			mp2[i]=m2[i];
			if(m1[i]!=0)
			{
				f1=1;
			}
			if(m2[i]!=0)
			{
				f2=1;
			}
			if(m3[i]!=0)
			{
				f3=1;
			}
		}
        
		if((f2==0)&&(f3==0))
		{
			sort(m1,m1+n);
			for(int j=n;j>kk;j--)
			{
				ans+=m1[j];
			}
		}
		else if((f1==0)&&(f3==0))
		{
			sort(m2,m2+n);
			for(int j=n;j>kk;j--)
			{
				ans+=m2[j];
			}
		}
		else if((f1==0)&&(f2==0))
		{
			sort(m3,m3+n);
			for(int j=n;j>kk;j--)
			{
				ans+=m3[j];
			}
		}
		else if((f1==0)&&(f2!=0)&&(f3!=0))
		{
			sort(m2,m2+n);
			for(int i=n;i>=1;i--)
			{
				for(int jj=1;jj<=n;jj++)
				{
					if(mp2[jj]==m2[i])
					{
						if(m2[i]>=m3[jj])
						{
							ans+=m2[i];
							pp++;
						}
						else
						{
							ans+=m3[jj];
						}
						mp1[jj]=-1;
						m2[jj]=-1;
						m3[jj]=-1;
						continue;
					}
				}
				if(pp>=kk)
				{
					continue;
				}
			}
			sort(m3,m3+n);
			if(pp==kk)
			{
				for(int ss=n;ss>kk;ss--)
				{
					if(m3[ss]==-1)
					{
						continue;
					}
					else
					{
						ans+=m3[ss];
					}
				}
			}
		}
		else
		{
			sort(m1,m1+n);
			for(int i=n;i>=1;i--)
			{
				for(int jj=1;jj<=n;jj++)
				{
					if(mp1[jj]==m1[i])
					{
						if((m1[i]>=m2[jj])&&(m1[i]>=m3[jj]))
						{
							ans+=m1[i];
							pp++;
						}
						if((m1[i]<m2[jj])&&(m2[jj]>m3[jj]))
						{
							ans+=m2[jj];
						}
						if((m1[i]<m3[jj])&&(m2[jj]<m3[jj]))
						{
							ans+=m3[jj];
						}
						mp1[jj]=-1;
						m2[jj]=-1;
						m3[jj]=-1;
						continue;
					}
				}
				if(pp>=kk)
				{
					continue;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
