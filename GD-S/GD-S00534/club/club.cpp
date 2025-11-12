#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N][3],d[N],ans;
int b[N][3],tot;
bool cmpd(long long x,long long y)
{
	if(x>y)
	return 1;
	return 0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n,s1,s2,s3,i;
	scanf("%d",&T);
	while(T>0)
	{
		T--;ans=0;s1=s2=s3=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			b[i][0]=0;b[i][1]=1;b[i][2]=2;
		}
		for(i=1;i<=n;i++)
		{
			if(a[i][b[i][0]]<a[i][b[i][1]])
			swap(b[i][0],b[i][1]);
			if(a[i][b[i][1]]<a[i][b[i][2]])
			swap(b[i][1],b[i][2]);
			if(a[i][b[i][0]]<a[i][b[i][1]])
			swap(b[i][0],b[i][1]);
			ans+=a[i][b[i][0]];
			if(b[i][0]==0)
			s1++;
			if(b[i][0]==1)
			s2++;
			if(b[i][0]==2)
			s3++;
		}
		if(s1>n/2)
		{
			tot=0;
			for(i=1;i<=n;i++)
			{
				if(b[i][0]==0)
				d[++tot]=a[i][b[i][1]]-a[i][b[i][0]];
			}
			sort(d+1,d+tot+1,cmpd);
			for(i=1;i<=tot&&s1>n/2;i++,s1--)
			ans+=d[i];
		}
		if(s2>n/2)
		{
			tot=0;
			for(i=1;i<=n;i++)
			{
				if(b[i][0]==1)
				d[++tot]=a[i][b[i][1]]-a[i][b[i][0]];
			}
			sort(d+1,d+tot+1,cmpd);
			for(i=1;i<=tot&&s2>n/2;i++,s2--)
			ans+=d[i];
		}
		if(s3>n/2)
		{
			tot=0;
			for(i=1;i<=n;i++)
			{
				if(b[i][0]==2)
				d[++tot]=a[i][b[i][1]]-a[i][b[i][0]];
			}
			sort(d+1,d+tot+1,cmpd);
			for(i=1;i<=tot&&s3>n/2;i++,s3--)
			ans+=d[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
