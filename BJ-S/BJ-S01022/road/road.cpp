#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<time.h>
using namespace std;
#define maxn (int)1e4
#define maxk 10
int n,m,k,cnt=0;
long long ans2;
vector<pair<long long,pair<int,int>>>vv;
bool used[1<<maxk];
int p[maxn+10],s[maxn+10];
long long c[maxn+10];
int find(int x)
{
	if(p[x]==x)return x;
	else return p[x]=find(p[x]);
}
bool merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)return false;
	if(s[x]<s[y])swap(x,y);
	p[y]=x;
	s[x]+=s[y];
	return true;
}
long long calc(int x)
{
	long long res=0;
	for(int i=1;i<=k;i++)
		if((x>>(i-1))&1)res+=c[i];
	for(int i=1;i<=n+k;i++)
	{
		p[i]=i;
		s[i]=1;
	}
	for(int i=0;i<vv.size();i++)
		if((vv[i].second.first<=n||((x>>vv[i].second.first-n-1)&1))&&(vv[i].second.second<=n||((x>>vv[i].second.second-n-1)&1))&&merge(vv[i].second.first,vv[i].second.second))res+=vv[i].first;
	return res;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	srand(time(0));
	for(int i=0,u,v;i<m;i++)
	{
		long long w;
		scanf("%d%d%lld",&u,&v,&w);
		vv.push_back({w,{u,v}});
	}
	for(int i=1;i<=k;i++)
	{
		long long x;
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&x);
			vv.push_back({x,{n+i,j}});
		}
	}
	sort(vv.begin(),vv.end());
	ans2=min(calc(0),calc((1<<k)-1));
	used[0]=used[(1<<k)-1]=true;
	for(int i=0;i<min((int)1e8/m,(1<<k));i++)
	{
		int x=rand()%(1<<k);
		while(used[x])x=rand()%(1<<k);
		used[x]=true;
		ans2=min(ans2,calc(x));
	}
	printf("%lld\n",ans2);
	return 0;
}
