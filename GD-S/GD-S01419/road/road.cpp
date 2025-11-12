#include<iostream>
#include<algorithm>
using namespace std;
struct sid{
	int u,v,w;
}a[2000010];
int c[20],ac[20][10010];
bool cmp(sid q,sid e)
{
	return q.w<e.w;
}
int p[10010],n,m,k;
void play()
{
	sort(a+1,a+m+1,cmp);
	int ans=a[1].w;
	p[a[1].u]=1;
	p[a[1].v]=1;
	for(int i=2;i<n;i++)
	{
		int ud=2;
		while(p[a[ud].u]==p[a[ud].v])ud+=1;
		p[a[ud].u]=1;
		p[a[ud].v]=1;
		ans+=a[ud].w;
	}
	for(int i=n-k+1;i<=n;i++)
	if(p[i]!=0)ans+=c[i+k-n];
	cout<<ans;
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>ac[i][j];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			m+=1;
			a[m].u=n+i;
			a[m].v=j;
			a[m].w=ac[i][j];
		}
	}
	n+=k;
	play();
	return 0;
}
