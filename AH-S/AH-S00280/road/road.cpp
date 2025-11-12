#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+30,M=1e6+10;
long long n,m,k,c[N],fa[N],siz[N],f[N],ct[N][N];
struct node
{
	long long u,v,w;
}a[M];
priority_queue<pair<long long,long long> >q;
long long find(long long x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
long long tree()
{
	long long u,v,w,id,s=0,cnt=0;
	for(long long i=1;i<=n+k;i++)fa[i]=i;
	while(!q.empty()){
		if(cnt==n+k-1)break;
		id=q.top().second;
		u=a[id].u,v=a[id].v,w=a[id].w;
		q.pop();
		if(fa[u]==fa[v])continue;
		if(siz[u]>siz[v])swap(u,v);
		fa[u]=v;
		s+=w;
		cnt++;
	}
	return s;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		q.push(make_pair(-1*a[i].w,i));
	}
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++){
			cin>>ct[i][j];
			m++;
			a[m].u=m,a[m].v=j,a[m].w=ct[i][j];
			q.push(make_pair(-1*(a[m].w+c[i]),m));
		}
	}
	cout<<tree();
	return 0;
}
