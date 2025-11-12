#include<bits/stdc++.h>
#define int long long
using namespace std;
struct road{
	int x,y,w;
};
bool b[107];
int n,m,k,mn=LONG_LONG_MAX,c[1000017];
int g[17][100017],fa[1000017];
road a[1000017];
vector<road> sv; 
int find(int x)
{
	return x==fa[x] ? x : (fa[x]=find(fa[x]));
}
void mg(int x,int y)
{
	fa[find(x)]=find(y);
	return;
}
bool cmp(road x,road y)
{
	return x.w<y.w;
}
void solve()
{
	int ret=0,adw=0;
	vector<road> v;
	v=sv;
	for(int i=1;i<=n+k+1;++i) fa[i]=i;
	for(int i=1;i<=k;++i){
		if(b[i]==0) continue;
		adw+=c[i];
		for(int j=1;j<=n;++j){
			v.push_back((road){i+n,j,g[i][j]});
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();++i){
		int x=v[i].x,y=v[i].y;
		if(find(x)!=find(y)){
			ret+=v[i].w;
			mg(x,y);
		}
	}
//	cout<<ret<<" ";
//	for(int i=1;i<=k;++i) cout<<b[i]<<" ";
//	cout<<"\n";
	mn=min(mn,ret+adw);
	return;
}
void dfs(int x)
{
	if(mn==0) return;
	if(x==k+1){
		solve();
		return;
	}
	b[x]=1;
	dfs(x+1);
	b[x]=0;
	dfs(x+1);
	return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].w);
		sv.push_back(a[i]);
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			scanf("%lld",&g[i][j]);
		}
	}
	if(m*pow(2,k)>=100000000){
		solve();
		for(int i=1;i<=k;++i){
			int sum=c[i];
			for(int j=1;j<=n;++j) sum+=g[i][j];
			mn=min(mn,sum);
		}
		cout<<mn<<"\n";
		return 0;
	}
	dfs(1);
	cout<<mn;
	return 0;
}
