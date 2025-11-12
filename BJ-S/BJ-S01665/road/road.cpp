#include <iostream>
#include <algorithm>
using namespace std;
int n,m,k,fa[1000005];
long long ans;
struct nood{int u,v,w;}a[1000005];
bool cmp(nood x,nood y){return x.w<y.w;}
void merge(int u,int v){fa[u]=fa[v];}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i<=m;i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	if(k==0)
	{
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++)
			fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			if(fa[a[i].u]!=fa[a[i].v])
			{
				ans+=a[i].w;
				fa[a[i].v]=fa[a[i].u];
			}
		}
		cout << ans;
	}
	return 0;
}
