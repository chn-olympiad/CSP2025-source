#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans=LLONG_MAX;
struct nd{
	int u,v,w;
}a[1000005],aa[1000005];
int b[15][10005],c[10005];
bool fb[15];
int fa[10005];
int find(int a){
	if(a==fa[a])return a;
	return fa[a]=find(fa[a]);
}
bool cmp(nd a,nd b){
	return a.w<b.w;
}
int kruskal(){
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		aa[i]=a[i];
		for(int j=1;j<=k;j++){
			if(!fb[j])continue;
			aa[i].w=min(aa[i].w,b[j][a[i].u]+b[j][a[i].v]);
		}
	}
	sort(aa+1,aa+m+1,cmp);
	int cnt=0,ct=0;
	for(int i=1;i<=m;i++){
		int fu=find(aa[i].u),fv=find(aa[i].v);
		if(fu==fv)continue;
		cnt+=aa[i].w;
		fa[fu]=fv;
		ct++;
		if(ct==n-1)break;
	}
	return cnt;
}
void dfs(int fl,int sum){
	if(fl==k+1){
		ans=min(kruskal()+sum,ans);
		return;
	}
	fb[fl]=1;
	dfs(fl+1,sum+c[fl]);
	fb[fl]=0;
	dfs(fl+1,sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	int cc=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)cc=1;
		for(int j=1;j<=n;j++)
			cin>>b[i][j];
	}
	if(!cc){
		for(int i=1;i<=k;i++)fb[i]=1;
		ans=kruskal();
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
