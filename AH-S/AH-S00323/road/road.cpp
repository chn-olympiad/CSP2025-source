#include<bits/stdc++.h>
using namespace std;


using LL=long long;
const int N=1e6+10,RES=1e4+10;
LL n,m,k,ans;

struct Node{
	LL u,v,w;
} a[N];

LL mor[13][RES];
LL mon[13];//gaizao feiyong
bool use[13];

LL calc()
{
	
	return 1;
}

void dep(LL now)
{
	if(now>k) ans=min(ans,calc());
	else
	{
		use[now]=1;
		dep(now+1);
		use[now]=0;
		dep(now+1);
	}
	return;
}

bool cmp(Node a1,Node a2)
{
	return a1.w<a2.w;
}

int fa[N];

int find(int i)
{
	if(fa[i]==i) return i;
	fa[i]=find(fa[i]);
	return fa[i];
}

LL temp1()
{
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	sort(a+1,a+m+1,cmp);
	
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].u)!=find(a[i].v))
		{
			fa[a[i].u]=find(a[i].v);
			ans+=a[i].w;
		}
	}
	
	
	
	return ans;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	//int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
		if(a[i].u>a[i].v) swap(a[i].u,a[i].v);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&mon[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&mor[i][j]);
		}
	}
	
	if(k==0)
	{
		cout<<temp1()<<endl;
	}
	else
	dep(1);
	
	
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
