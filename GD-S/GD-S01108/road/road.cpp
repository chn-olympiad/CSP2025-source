#include<bits/stdc++.h>
using namespace std;
struct tt{
	int u,v,w;
}te[1000005],e[1000005];
bool cmp(tt x,tt y){
	return x.w<y.w;
}
int n,m,k,kk,ans=1e9,c[20005],f[20005],a[105][10005];
bool bj[20005];
int find(int d){
	if(d==f[d]) return d;
	return f[d]=find(f[d]);
}
int work(){
	int s=0,ks=0;
	kk=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=k+m;i++) e[i].u=e[i].v=e[i].w=0;
	for(int i=1;i<=m;i++){
		e[++kk]=te[i];
	}
	for(int i=1;i<=k;i++){
		if(bj[i]==1){
			s+=c[i];
			for(int j=1;j<=n;j++){
				e[++kk].u=i+n;
				e[kk].v=j;
				e[kk].w=a[i][j];
			}
		}
	}
	sort(e+1,e+kk+1,cmp);
	for(int i=1;i<=kk;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv) continue;
		ks++;
		f[fu]=fv;
		s+=e[i].w;
		if(ks==n+k-1) break;
	}
	return s;
}
void dfs(int d){
	if(d==k+1){
		ans=min(ans,work());
		return;
	}
	bj[d]=1;
	dfs(d+1);
	bj[d]=0;
	dfs(d+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>te[i].u>>te[i].v>>te[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
