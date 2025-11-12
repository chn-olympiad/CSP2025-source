#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,k,u,v,w,c,w2[N];
int W[N][N],F;
long long ans; 
int f[N];
struct xi
{
	int l,r,w;
};
void re()
{
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(w2[i]+c+w2[j]<W[i][j] || !W[i][j])
			{
				W[i][j]=w2[i]+c+w2[j];
				W[j][i]=w2[i]+c+w2[j];
			}
	return ;
}
bool cmp(xi x ,xi y)
{
	return x.w<y.w;
}
void fd(int l)
{
	if(f[l]!=l)
	{
		fd(f[l]);
		f[l]=f[f[l]];
	}
	return ;
 } 
void Ans()
{
	xi v[(n-1)*n/2+10];
	int s=0,S=1,x=1;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			s++;
			v[s].l=i;
			v[s].r=j;
			v[s].w=W[i][j];
		}
	sort(v+1,v+1+s,cmp);
	while(S<n)
	{
		while(f[v[x].l]==f[v[x].r])
			x++; 
		fd(v[x].l);
		ans+=v[x].w;
		S++;
		v[x].r=v[x].l;
		x++;
	}
	return ;
}
int main()
{
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		W[u][v]=w;
		W[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c);
		for(int j=1;j<=n;j++)
			scanf("%d",&w2[j]);
		re();
	}
	Ans();
	cout<<ans;
	return 0;
} 
