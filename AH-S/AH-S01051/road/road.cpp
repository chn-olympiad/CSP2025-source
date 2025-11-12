#include<bits/stdc++.h>
using namespace std;
struct Node{
	int u,v,w;
}s[2000010];
int n,m,k;
int c[15],a[10020][15];
int bcj[10020];
int find(int x)
{
	if(bcj[x]!=x)return bcj[x]=find(bcj[x]);
	return bcj[x];
}
bool cmp(Node x,Node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long sum=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&s[i].u,&s[i].v,&s[i].w);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",c+i);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j][i]);
			s[++m]={i+n,j,a[j][i]};
		}
	}
	sort(s+1,s+m+1,cmp);
	for(int i=1;i<=n+k;i++)bcj[i]=i;
	int p=n+k;
	for(int i=1;i<=m;i++)
	{
		Node tmp=s[i];
		int fa=find(tmp.u),fb=find(tmp.v);
		if(fa!=fb)
		{
			bcj[fa]=fb,p--,sum+=tmp.w;
			p--;
			if(p==1)break;
		}
	}
	cout<<sum;
	return 0;
}
