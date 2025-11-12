#include<bits/stdc++.h>
using namespace std;
int n,m,r,cnt,vis[10005];
long long ans,vv,o,a[10005][10005],h[10005],t[10005];
pair<long long,pair<long long,long long>> oo;
priority_queue<pair<long long,pair<long long,long long>>,vector<pair<long long,pair<long long,long long>>>,greater<pair<long long,pair<long long,long long>>>> q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&r);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=100000000000;
	for(int i=1;i<=m;i++)
	{
		long long x,y,z;
		scanf("%lld %lld %lld",&x,&y,&z);
		a[x][y]=min(a[x][y],z);
		a[y][x]=min(a[y][x],z);
	}
	for(int i=1;i<=r;i++)
	{
		long long xx;
		scanf("%lld",&xx);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&t[j]);
			t[j]+=xx;
		}
		for(int g=1;g<=n;g++)
			for(int h=g+1;h<=n;h++)
			{
				if(t[g]+t[h]-xx<a[g][h]&&g!=h)
					a[g][h]=t[g]+t[h]-xx,a[h][g]=t[g]+t[h]-xx;
			}
	}
	for(long long i=1;i<=n;i++)
		for(long long j=i+1;j<=n;j++)
			if(a[i][j]!=100000000000)
			{
				oo.first=a[i][j],oo.second.first=i,oo.second.second=j;
				q.push(oo);
			}
//	while(!q.empty())
//	{
////		printf("1");
//		printf("%lld %lld %lld\n",q.top().second.first,q.top().second.second,q.top().first);
//		q.pop();
//	}
	int bj=1;
	while(bj==1)
	{
		bj=0;
		long long x=q.top().second.first,y=q.top().second.second;
		while(vis[x]==1&&vis[y]==1)
		{
			q.pop();
			x=q.top().second.first,y=q.top().second.second;
		}
		vis[x]=1,vis[y]=1;
//		printf("%lld %lld %lld\n",q.top().second.first,q.top().second.second,q.top().first);
		ans+=q.top().first;
		for(int i=1;i<=n;i++)
			if(vis[i]==0)
			{
				bj=1;
				break;
			}
	}
//	printf("\n");
//	for(int i=1;i<=n;i++)
//		if(vis[i]==0)
//			printf("%d ",i);
	printf("%lld",ans);
	return 0;
}
