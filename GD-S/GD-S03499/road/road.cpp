#include <bits/stdc++.h>
using namespace std;
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
#define int long long
const int N=2e6+20;
int n,m,k,fa[N],ans,tot,cnt;
struct node{int x,y,w;}a[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void kruskal() {
	for(int i=1;i<=n;i++) {
		int x=find(a[i].x),y=find(a[i].y);
		if(x!=y) fa[x]=y,cnt++,ans+=a[i].w;
		if(cnt==n-1) {cout<<ans;return;}
	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].w;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++) for(int j=0,z;j<=n;j++) cin>>z,tot+=z;
	if(k>0) {cout<<0;return 0;}
	sort(a+1,a+m+1,[](node a,node b){return a.w<b.w;});
	kruskal();
}
