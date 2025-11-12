#include<bits/stdc++.h>
#define int long long
using namespace std;
const int BIG=1e6+1000;
int f[BIG],n,m,k,ans;
struct ff{
	int x,y,w;
}a[BIG];
int bcj(int x)
{
	if(f[x]==x)return x;
	else return f[x]=bcj(f[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=0;i<=n+1;i++)f[i]=i;
	for(int i=1;i<=m;i++)
		cin>>a[i].x>>a[i].y>>a[i].w;
	sort(a+1,a+1+m,[](ff x,ff y){return x.w<y.w;});
	for(int i=1;i<=m;i++)
	{
		int fx=bcj(a[i].x),fy=bcj(a[i].y);
		if(fx!=fy)ans+=a[i].w,f[fy]=fx;
	}
	cout<<ans;
	return 0;
}
