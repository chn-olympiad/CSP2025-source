#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10005],f[10005];
long long ans;
struct N
{
	int w,x,y;
};
priority_queue<N>q;
bool operator < (N xf,N yf)
{
	return xf.w>yf.w;
}
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		q.push({z,x,y});
	}
	for(int i=1;i<=k;i++)
	{
		int x;
		scanf("%d",&x);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++) q.push({a[i]+a[j],i,j});
		}
	}
	int x=0;
	while(x<n-1)
	{
		if(x==n-1) break;
		N y=q.top();q.pop();
		int xf=y.x,yf=y.y,w=y.w;
		int xx=find(xf),yy=find(yf);
		if(xx==yy) continue;
		f[yy]=xx;
		ans+=w;x++;
	}
	cout<<ans;
	return 0;
}
