#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[26][1026],r,f[10005],cx,ans=0;
struct uuu{
	int u;
	int v;
	int w;
}a[2000026];
bool cmp(uuu xx,uuu yy){
	return xx.w<yy.w;
}
int find(int x)
{
	if(f[x]==x)
	{
		return x;
	}
	else
	{
		return f[x]=find(f[x]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i][0]);
		cx=max(cx,c[i][0]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&c[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	if(cx==0)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(c[i][j]==0)
				{
					for(int o=1;o<=n;o++)
					{
						m++;
						if(o!=j)
						{
						a[m].u=o;
						a[m].u=j;
						a[m].w=c[i][o];
						}
					}
					break;
				}
			}
		}
	}
	r=0;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++)
	{
		if(find(a[i].u)!=find(a[i].v))
		{
			f[a[i].u]=find(a[i].v);
			r++;
			ans+=a[i].w;
			if(r==n-1)
			{
				break;
			}
		}
	}
	if(k==0)
	{
		cout<<ans;
		return 0;
	}
	cout<<ans;
	return 0;
}


























