#include<bits/stdc++.h>
using namespace std;
int mp[10001][10001];
int p[10001][11];
int fa[10001];
struct point{
	int x;int y;int val;
}km[3000001];
int s[10001];
bool cmp(const point &x,const point &y)
{
	return x.val<y.val;
}
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void add(int x,int y)
{
	fa[x]=y;
}
int main()
{
	int n,m,k;int num=0;int nump=0;int nump2=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		int u,v,w;cin>>u>>v>>w;
		mp[u][v]=w;
		km[++num].x=u;km[num].y=v;
		km[num].val=w;
	}
	for(int i=1;i<=k;i++) {
		for(int j=1;j<=n;j++) {
			cin>>p[j][i];
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(km+1,km+1+num,cmp);
	for(int i=1;i<=num;i++) {
		if(fa[km[i].x]!=fa[km[i].y]) {
			add(fa[km[i].x],fa[km[i].y]);nump+=km[i].val;
		}
	}
	for(int i=1;i<=k;i++) {
		for(int j=1;j<=n;j++) {
			km[++num].x=j;km[num].y=i;
			km[num].val=p[j][i];
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i; 
	sort(km+1,km+1+num,cmp);
	for(int i=1;i<=num;i++) {
		if(fa[km[i].x]!=fa[km[i].y]) {
			add(fa[km[i].x],fa[km[i].y]);nump2+=km[i].val;
		}
	}
	void dfs()
	cout<<min(nump,nump2)<<endl;
	return 0;
}
