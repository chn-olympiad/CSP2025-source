#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],c[100005],e[100005],d[100005],f[100005],lf;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int ans=0,l1=0,l2=0,l3=0,s=0;
		lf=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			ans+=max(a[i],max(b[i],c[i]));
			if(a[i]>=b[i]&&a[i]>=c[i])
				e[i]=1,d[i]=a[i]-max(b[i],c[i]),l1++;
			else if(b[i]>=a[i]&&b[i]>=c[i])
				e[i]=2,d[i]=b[i]-max(a[i],c[i]),l2++;
			else
				e[i]=3,d[i]=c[i]-max(b[i],a[i]),l3++;
		}
		if(l1>n/2)
		{
			s=l1-(n/2);
			for(int i=1;i<=n;i++)
				if(e[i]==1)
					f[++lf]=d[i];
		}
		if(l2>n/2)
		{
			s=l2-(n/2);
			for(int i=1;i<=n;i++)
				if(e[i]==2)
					f[++lf]=d[i];
		}
		if(l3>n/2)
		{
			s=l3-(n/2);
			for(int i=1;i<=n;i++)
				if(e[i]==3)
					f[++lf]=d[i];
		}
		if(lf)
			sort(f+1,f+1+lf);
		for(int i=1;i<=s;i++)
			ans-=f[i];
		printf("%d\n",ans);
	}
	return 0;
} 
