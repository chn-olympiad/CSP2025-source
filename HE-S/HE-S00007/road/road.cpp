#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,k,p[N],c[15][N],cnt,ans;
struct node{
	int u,v,w;
}a[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int get_p(int x){
	return p[x]==x?x:p[x]=get_p(p[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++) 
	{
		cin>>c[i][0];
		for(int j=1;j<=n;j++) cin>>c[i][j];
	} 
	 for(int i=1;i<=m;i++)
	 {
	 	if(get_p(a[i].u)!=get_p(a[i].v)) 
	 	{
	 		ans+=a[i].w;
	 		p[get_p(a[i].u)]=get_p(a[i].v);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
