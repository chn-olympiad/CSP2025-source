#include<bits/stdc++.h>
using namespace std;
struct pos
{
	int bj,w;
}_ansf[100005],_anss[100005],_dp[100005],c[10];
int n,t,d[5];
long long sum=0;
bool cmp(pos x,pos y)
{
	return x.w<y.w;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		d[1]=n/2;
		d[2]=n/2;
		d[3]=n/2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&c[1].w,&c[2].w,&c[3].w);
			c[1].bj=1;
			c[2].bj=2;
			c[3].bj=3;
			sort(c+1,c+4,cmp);
			_ansf[i].w=c[3].w;
			_anss[i].w=c[2].w;
			_ansf[i].bj=c[3].bj;
		}
		for(int i=1;i<=n;i++)
		{
			sum+=_anss[i].w;
			_dp[i].w=_ansf[i].w-_anss[i].w;
			_dp[i].bj=_ansf[i].bj;
		}
		sort(_dp+1,_dp+1+n,cmp);
		for(int i=n;i>=1;i--)
		{
			if(d[_dp[i].bj]>0)
			{
				sum+=_dp[i].w;
				d[_dp[i].bj]--;
			}
		}
		printf("%lld",sum);
		printf("\n");
	}
	return 0;
}
