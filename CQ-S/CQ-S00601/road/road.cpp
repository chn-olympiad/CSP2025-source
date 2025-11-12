#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
const int maxm=1e6+5;
struct edge{
	int from,to,val;
}tmp;
priority_queue <edge> q;
bool operator<(edge a,edge b)
{
	return a.val>b.val;
}
int n,m,k,cnt;
long long ans;
int c[15],fa[maxn+10];
bool vis[maxn];
int p[maxn];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void kruskal()
{
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		tmp=q.top();
		q.pop();
		int u=find(tmp.from),v=find(tmp.to);
		if(u!=v){
			fa[u]=v;
			ans+=tmp.val;
			if(tmp.from<=n && !vis[tmp.from]) cnt++,vis[tmp.from]=1;
			if(tmp.to<=n && !vis[tmp.to]) cnt++,vis[tmp.to]=1;
			if(tmp.from>n) p[tmp.from-n]++;
			if(tmp.to>n) p[tmp.to-n]++;
		}
		if(cnt==n) break;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,l;
		cin>>x>>y>>l;
		tmp.from=x,tmp.to=y,tmp.val=l;
		q.push(tmp);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int x;
		for(int j=1;j<=n;j++){
			cin>>x;
			tmp.from=i+n,tmp.to=j,tmp.val=x+c[i];
			q.push(tmp);
			m++;
		}
	}
	kruskal();
	for(int i=1;i<=k;i++)
		while(p[i]>1) ans-=c[i],p[i]--;
	cout<<ans;
	return 0;
}

