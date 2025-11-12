#include<bits/stdc++.h>
using namespace std;
struct qq{
	int a,ip;
}b[5];
bool cmp(qq x,qq y)
{
	return x.a > y.a;
}
int t,n,f[5],a[5][100005],c[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		long long ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&b[1].a,&b[2].a,&b[3].a);
			b[1].ip=1;b[2].ip=2;b[3].ip=3;
			sort(b+1,b+1+3,cmp);
			a[b[1].ip][++f[b[1].ip]]=b[1].a-b[2].a;
			ans+=b[1].a;
		}
		for(int i=1;i<=3;i++)
			if(f[i] > (n/2))
			{
				int la=f[i]-(n/2);
				for(int j=1;j<=f[i];j++)
					c[j]=a[i][j];
				sort(c+1,c+1+f[i]);
				for(int j=1;j<=la;j++)
					ans-=c[j];
			}
		printf("%lld\n",ans);
	}
	return 0;
}
