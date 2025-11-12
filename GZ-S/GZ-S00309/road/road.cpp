//GZ-S00309 贵阳中天中学 王化城
#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
long long n,m,k,fa[N],a[105][N],c[N];
long long ans=0;
struct node{
	long long u,v,w;
} r[N];
bool cmp(node x,node y) {
	return x.w<y.w;
}
int search(int x) {
	if(fa[x]==x) return x;
	return fa[x]=search(fa[x]);
}
void kl() {
	int tl=0;
	for(int i=1; i<=m+k*n; i++) {
		if(tl==n-1+k) break;
		int fu=search(r[i].u),fv=search(r[i].v);
		if(fu!=fv) {
			fa[fu]=fv;
			tl++;
			ans+=r[i].w;
		}
	}
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++) {
		long long u,v,w;
		cin>>u>>v>>w;
		r[i].u=u,r[i].v=v,r[i].w=w;
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
			r[m+n*(i-1)+j].u=i+m,r[m+n*(i-1)+j].v=j,r[m+n*(i-1)+j].w=a[i][j]+c[i];
		}
	}
	sort(r+1,r+m+k*n+1,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	kl();
	cout<<ans;
	return 0;
}
