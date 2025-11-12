#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long n,m,ans,i,t,c[110000],j;
vector<long long> d[5];
struct node
{
	long long w,id;
}sum[5],a[5];
bool cmp(node x,node y)
{
	return x.w>y.w; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=1;i<=3;i++) 
		{
		 sum[i].id=i;
		 sum[i].w=0;
		 d[i].clear();
	    }
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[1].w,&a[2].w,&a[3].w);
			a[1].id=1;
			a[2].id=2;
			a[3].id=3;
			sort(a+1,a+1+3,cmp);
			sum[a[1].id].w++;
			d[a[1].id].push_back(a[1].w-a[2].w);
			ans+=a[1].w;
		}
		sort(sum+1,sum+1+3,cmp);
		if(sum[1].w>(n/2))
		{
			for(i=0;i<sum[1].w;i++) c[i+1]=d[sum[1].id][i];
			sort(c+1,c+1+sum[1].w);
			for(i=1,j=n/2+1;j<=sum[1].w;j++,i++)
			{
				ans=ans-c[i];
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
