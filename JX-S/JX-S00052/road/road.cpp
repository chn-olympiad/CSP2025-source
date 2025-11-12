#include<bits/stdc++.h>
using namespace std;
int n,k,m,w[10010][10010],ans,k1[10010],an;bool v[10010];
struct sp{
	int l,r,w;
}a[10010];
bool cmp(sp x,sp y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		w[min(x,y)][max(x,y)]=z;
	}
	
	for(int i=1;i<=k;i++)
	{
		int x;cin>>x;
		for(int j=1;j<=n;j++)
		{
			cin>>k1[j];
		}
		for(int j=1;j<n;j++)
		{
			for(int l=j+1;l<=n;l++) 
			{
				if(w[j][l]!=0) w[j][l]=min(w[j][l],x+k1[j]+k1[l]);
				else w[j][l]=x+k1[j]+k1[l];
			}
		}
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(w[i][j]!=0)
			{
				an++;
				a[an].l=i;a[an].r=j;a[an].w=w[i][j];
			}
		}
	}
	sort(a+1,a+1+an,cmp);
	
	for(int i=1;i<=an;i++)
	{
		if(v[a[i].l]&&v[a[i].r]) continue;
		else 
		{
			ans+=a[i].w;
			v[a[i].l]=1;v[a[i].r]=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
