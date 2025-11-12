#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+15,M=1e6+5;
int n,m,k,c[15],co[15][N],f[N],ans=1e18;
int cnt,fa[N];
struct node{
	int x,y,w;
}a[2*M],aa[2*M];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int query(){
	int sum=0,nn=n;
	cnt=m;
	for(int i=1;i<=m;i++){
		aa[i].x=a[i].x,aa[i].y=a[i].y,aa[i].w=a[i].w;
	}
	for(int i=1;i<=k;i++){
		if(f[i]==1){
			sum+=c[i];
			nn++;
			for(int j=1;j<=n;j++){
				cnt++;
				aa[cnt].x=nn;
				aa[cnt].y=j;
				aa[cnt].w=co[i][j];
			}
		}
	}
	sort(aa+1,aa+cnt+1,cmp);
	for(int i=1;i<=nn;i++) fa[i]=i;
	int tot=0;
	for(int i=1;i<=cnt;i++){
		int fx=find(aa[i].x),fy=find(aa[i].y);
		if(fx!=fy){
			sum+=aa[i].w;
			fa[fx]=find(fy);
			tot++;
		}
		if(tot==nn-1) break;
	}
	return sum;
	
}
void dfs(int x){
	if(x>k){
		ans=min(ans,query());
		return ;
	}
	f[x]=1;
	dfs(x+1);
	f[x]=0;
	dfs(x+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>co[i][j];
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
