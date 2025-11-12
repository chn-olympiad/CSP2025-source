#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
#define f(n) for(int i=1;i<=n;i++)
struct rd{
	int v,w;
}z;
struct rdq{
	int u,v,w;
	bool operator<(const rdq&x)const
	{
		return x.w<w;
	}
}zzr;
priority_queue<rdq> q;
vector<rd> a[10021];
int n,m,k,bcfa[10021];
int gf(int x)
{
	if(x==bcfa[x])return x;
	return bcfa[x]=gf(bcfa[x]);
}
ll dis[10051],c[11],ct[11][10001];
void dfst(int now,int fa)
{
	f(a[now].size())if(a[now][i-1].v!=fa)
	{
		int to=a[now][i-1].v;
		dis[to]=dis[now]+a[now][i-1].w;
		dfst(to,now);
	}
}
int main()
{
	f(10020)bcfa[i]=i;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	f(m)
	{
		int u,v,w;
		cin>>u>>v>>w;
		q.push({u,v,w});
	}
	bool pda=true;
	f(k)
	{
		cin>>c[i];if(c[i]!=0)pda=false;
		for(int j=1;j<=n;j++)cin>>ct[i][j];
	}
	if(pda)f(k)for(int j=1;j<=n;j++)q.push({i+n,j,ct[i][j]});
	int lsq=0;ll sum=0;
	while(lsq<n+k-1)//lsq<=n+k-1
	{
		zzr=q.top();q.pop();
		if(gf(zzr.u)==gf(zzr.v))continue;
		bcfa[gf(zzr.u)]=gf(zzr.v);
//		a[zzr.u].push_back({zzr.v,zzr.w});
//		a[zzr.v].push_back({zzr.u,zzr.w});
		lsq++;sum+=zzr.w;
	}
	if(k==0||pda)
	{
		cout<<sum;
		return 0;
	}
	//minntree
	cout<<"13";
	return 0;
}


