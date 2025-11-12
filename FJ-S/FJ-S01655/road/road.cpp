#include<bits/stdc++.h>
using namespace std;
struct zzz{
	int u;
	int v;
	int w;
}a[7000005];
bool pd(zzz x,zzz y)
{
	return x.w<y.w;
}
int belong[10005],ans,b[15][10005],t[15],sum;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int cnt=0,o=0,js=m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&t[i]);
		for(int o=1;o<=n;o++)
		{
			scanf("%d",&b[i][o]);
		}
		for(int j=1;j<=n;j++)
		for(int o=1;o<=n;o++)
		{
			js++;
			a[js].u=j;
			a[js].v=o;
			a[js].w=b[i][j]+b[i][o];
		}
	}
	sort(a+1,a+js+1,pd);
	for(int i=1;i<=n;i++) belong[i]=i;
	while(cnt<n-1&&o<js)
	{
		o++;
		if(belong[a[o].u]==belong[a[o].v])continue;
		cnt++;
		ans+=a[o].w;
	//	cout<<ans<<" "<<a[o].v<<" "<<o<<endl;
		int p=belong[a[o].v];
		for(int i=1;i<=n;i++)
		{
			if(belong[i]==p) belong[i]=belong[a[o].u];
		}
	}
	cout<<ans;
	return 0;
}
