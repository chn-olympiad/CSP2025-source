#include <bits/stdc++.h>
using namespace std;
int n,m,k,laji,vis[100005],f[100005],ans;
struct L{
	int u,v,w;
}t[1000005];
bool cmp(L x,L y){
	return x.w<y.w;
}
int find(int x){
	if (f[x]==x){
		return x;
	}
	if (find(f[x])!=f[x]){
		f[x]=find(f[x]);
	}
	return f[x];
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	f[fx]=f[fy];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>t[i].u>>t[i].v>>t[i].w;
	}
	for (int i=1;i<=k;i++)
	{
		cin>>laji;
		for (int j=1;j<=n;j++)
		{
			t[m+(i-1)*n+j].u=n+i;
			t[m+(i-1)*n+j].v=j;
			cin>>t[m+(i-1)*n+j].w;
		}
	}
	for (int i=1;i<=n+k;i++){
		f[i]=i;
	}
	sort(t+1,t+m+k*n+1,cmp);
	for (int i=1;i<=m+k*n;i++)
	{
		if (find(t[i].u)!=find(t[i].v))
		{
			merge(t[i].u,t[i].v);
			ans+=t[i].w;
		}
	}
	cout<<ans;
}
