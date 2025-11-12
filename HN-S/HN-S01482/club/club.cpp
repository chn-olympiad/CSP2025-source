#include<bits/stdc++.h>
#define ll long long
#define N 100002
using namespace std;
inline int in()
{
	int s=0,w=1;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')w=-1;c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		s=s*10+c-'0';c=getchar();
	}return s*w;
}

int t,n,a[N][4],sum1,sum2,sum3,b[N],o,ans,f[N];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=in();
	while(t--)
	{
		memset(a,0,sizeof a);memset(b,0,sizeof b);memset(f,0,sizeof f);o=sum1=sum2=sum3=ans=0;
		n=in();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				a[i][j]=in();
			}
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])f[i]=1,sum1++,ans+=a[i][1];
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])f[i]=2,sum2++,ans+=a[i][2];
			else f[i]=3,sum3++,ans+=a[i][3];
		}
		if(sum1>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(f[i]==1)
				b[++o]=a[i][1]-max(a[i][2],a[i][3]);
			}
		}
		else if(sum2>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(f[i]==2)
				b[++o]=a[i][2]-max(a[i][1],a[i][3]);
			}
		}
		else if(sum3>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(f[i]==3)
				b[++o]=a[i][3]-max(a[i][1],a[i][2]);
			}
		}
		sort(b+1,b+1+o);
		if(o>0) for(int i=1;i<=max(sum1,max(sum2,sum3))-n/2;i++)ans-=b[i];
		printf("%lld\n",ans);
	}
	return 0;
}

