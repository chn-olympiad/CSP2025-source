#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,long long> >q;
int f[5000001];
int c[5000001];
long long b[5000001];
int f1[5000001];
int fa[5000001];
	long long n,m,i,j,cnt=1,k,x,ans=0,u,v,w,y;
	long long s1=m;
int find(int x)
{
	if(fa[x]!=x)
	{
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(i=1;i<=m;i++)
{fa[i]=i;
	cin>>u>>v>>w;
	f[i]=u;
	f1[i]=v;
	q.push({-w,i});
}s1=m;
for(i=1;i<=k;i++)
{cin>>c[i];
fa[i+m]=i+m;
	for(j=1;j<=n;j++)
	{
		cin>>b[j];
		s1++;
		f[s1]=i+m;
		f1[s1]=j;
		q.push({-b[j],s1});
	}
}
while(q.size())
{
	x=q.top().second;
	y=q.top().first;
	q.pop();
	u=f[x];
	v=f1[x];
	if(find(u)==find(v))
	{
		continue;
	}
	else
	{
		ans-=y;
		fa[find(u)]=find(v);
	}
}
cout<<ans;
return 0;

} 
