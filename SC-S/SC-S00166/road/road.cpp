#include<bits/stdc++.h>//1e3  B-road 
using namespace std;
int n,m,k,fa[10005],ans,b[12][10005],cn,s,taskA=1;
struct cc{
	int u,v,w;
};
cc c[10050],a[1000005];
bool hel(cc l,cc r){
	return l.w<r.w;
}
int fid(int x){
	if(fa[x]==x) return x;
	fa[x]=fid(fa[x]);
	return fa[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
//	if(k==0){//============16
		for(int i=1;i<=n;i++){
		fa[i]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>a[i].u>>a[i].v>>a[i].w;
		}
		sort(a+1,a+n+1,hel);
		for(int i=1;i<=m;i++){
			fid(a[i].u);
			fid(a[i].v);
			if(fa[a[i].u]!=fa[a[i].v]){
				ans+=a[i].w;
				c[++cn].u=a[i].u,c[cn].v=a[i].v,c[cn].w=a[i].w;
				if(fa[a[i].u]<fa[a[i].v]) fa[fa[a[i].v]]=fa[a[i].u];
				else fa[fa[a[i].u]]=fa[a[i].v];
			}
		}
		cout<<ans;
		return 0;
}