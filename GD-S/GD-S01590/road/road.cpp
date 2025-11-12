 #include<bits/stdc++.h>
 using namespace std;
 struct edge{
 	int u,v,w;
 }e[1000003];
 int n,m,k,c[13],a[13][10003],f[10003];
 long long ans;
 bool cmp(edge x,edge y)
 {
 	return x.w<y.w;
 }
 int find(int x)
 {
 	if(f[x]!=x)
 		f[x]=find(f[x]);
 	return f[x];
 }
 int main()
 {
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	scanf("%d%d%d",&n,&m,&k);
 	for(int i=1;i<=n;i++)
 		f[i]=i;
 	for(int i=1;i<=n;i++)
 	{
 		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	 }
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int i=1;i<=n;i++)
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v)
		{
			ans+=e[i].w;
			f[u]=v;
		}
	}
	printf("%lld",ans);
 	return 0;
 }
