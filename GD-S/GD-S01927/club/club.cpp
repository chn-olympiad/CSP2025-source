#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5;
int T,c[3],a[N][3],n,p[N],A[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		c[0]=c[1]=c[2]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",a[i],a[i]+1,a[i]+2);
			p[i]=0;
			if(a[i][1]>a[i][0])
				p[i]=1;
			if(a[i][2]>a[i][p[i]])
				p[i]=2;
			c[p[i]]++;
		}
		LL ans=0;
		for(int i=1;i<=n;i++)
			ans+=a[i][p[i]];
		if(max({c[0],c[1],c[2]})>n/2)
		{
			int k=0,m=0;
			if(c[1]>n/2)
				k=1;
			if(c[2]>n/2)
				k=2;
			for(int i=1;i<=n;i++)
			{
				if(p[i]==k)
				{
					int mx=0;
					for(int j:{0,1,2})
						if(j!=k)
							mx=max(mx,a[i][j]);
					A[++m]=a[i][p[i]]-mx;
				}
			}
			sort(A+1,A+m+1);
			for(int i=1;i<=c[k]-n/2;i++)
				ans-=A[i];
		}
		printf("%lld\n",ans);
	}
}
