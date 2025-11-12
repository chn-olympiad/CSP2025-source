#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;
struct daan{
	long long u,v,ct;
}a[1000001],df[200001];
long long n,m,k,ct,gz[11][10001],cs[11],d[10001],ans=1e18;
bool boo[11];
long long getfather(long long x)
{
	while(d[x]!=x)
	  x=d[x]=d[d[x]];
	return x;
}
void union1(long long j,long long k)
{
	d[getfather(j)]=getfather(k);
}
bool same(long long j,long long k)
{
	return getfather(j)==getfather(k);
}
bool cmp(daan j,daan k)
{
	return j.ct<k.ct;
}
void dfs(long long x)
{
	if(x>k)
	{
		long long cnt=n-1,sum=0;
		for(int z=1;z<n;z++)
		{
			df[z]=a[z];
			d[z]=z;
		}
		for(int z=n;z<=n+k;z++)
		  d[z]=z;
		for(int z=1;z<=k;z++)
		{
			if(boo[z]==false)
			  continue;
			sum+=cs[z];
			for(int y=1;y<=n;y++)
			{	
				cnt++;
				df[cnt]=(daan){z+n,y,gz[z][y]};
			}
		}
		sort(df+1,df+1+cnt,cmp);
		long long num=0;
		for(int z=1;z<=cnt;z++)
		{
			if(same(df[z].u,df[z].v)==true)
			  continue;
			num++;
			sum+=df[z].ct;
			union1(df[z].u,df[z].v);
			if(num==n+k-1)
			  break;
		}
		ans=min(ans,sum);
		return;
	}
	dfs(x+1);
	boo[x]=true;
	dfs(x+1);
	boo[x]=false;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("bigdata.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int z=1;z<=m;z++)
	  cin>>a[z].u>>a[z].v>>a[z].ct;
	for(int z=1;z<=k;z++)
	{
		cin>>cs[z];
		for(int y=1;y<=n;y++)
		  cin>>gz[z][y];
	}
	for(int z=1;z<=n;z++)
	  d[z]=z;
	sort(a+1,a+1+m,cmp);
	for(int z=1;z<=m;z++)
	{
		if(same(a[z].u,a[z].v)==true)
		{
			a[z].ct=1e18;
			continue;
		}
		union1(a[z].u,a[z].v);
	}
	sort(a+1,a+1+m,cmp);
	dfs(1);
	cout<<ans;
}
/*
不是哥们
建两条路代价4+5
城市化加建路1+2
加起来不是12吗？从哪里多出来一个1
What can I say?

看明白了wssb 
但只能做出2^knlogn做法，运气不好得挂20分 
顺便押一下今年迷惑行为关键词：我
*/
