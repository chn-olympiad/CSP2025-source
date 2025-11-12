#include<bits/stdc++.h>
using namespace std;
int n,m,k,tmp,f[10005],fu,fv,cnt,ans;
struct edge
{
	int u,v,w;
}a[1000005];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int find(int pos)
{
	if(f[pos]==pos) return pos;
	return f[pos]=find(f[pos]); 
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&tmp);
		for(int i=1;i<=n;i++) scanf("%d",&tmp);
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		fu=find(a[i].u),fv=find(a[i].v);
		if(fu!=fv)
		{
			ans+=a[i].w,cnt++;
			if(cnt==n-1) break;
			f[fv]=fu;
		}
	}
	cout<<ans;
	return 0;
}
