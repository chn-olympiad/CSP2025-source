#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u,v;
	int w;	
} b[100005],xb[100005];
int f[100005];
int ffind(int x)
{
	if(x==f[x]) return x;
	else return f[x]=ffind(f[x]);
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].u>>b[i].v>>b[i].w;
		xb[i].w=b[i].w,xb[i].u=b[i].u,xb[i].v=b[i].v;
		f[i]=i;
	}
	int ans=0;
	int cnt=0;
    sort(xb+1,xb+1+cnt,cmp);
	for(int i=1;i<=k;i++) ;
	int kk=0;
	while(1)
	{
		kk++;
		if(ffind(xb[kk].u)!=ffind(xb[kk].v))
		{
			f[xb[kk].v]=xb[kk].u;
			ans+=xb[kk].w;
			cnt++;
			if(cnt>=n-1)
			break;
		}
	}
	cout<<ans;
	return 0;	
} 
