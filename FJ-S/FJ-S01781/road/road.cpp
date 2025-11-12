#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=1e4+5;
const int M=2e6+5;
int n,m,k;
ll c[20][N];
struct node {
	int x,y;
	ll w;
} a[M];
int fa[N];
int find(int x) {
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void add(int x,int y) {
	int fx=find(x),fy=find(y);
	if(fx!=fy) {
		fa[fx]=fy;
	}
}
bool cmp(node a,node b) {
	return a.w<b.w;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)fa[i]=i;
	int cnt=m;
	for(int i=1; i<=m; i++) {
		int x,y;
		ll w;
		cin>>x>>y>>w;
		a[i]= {x,y,w};
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i][0];
		int pos=0;
		for(int j=1; j<=n; j++) {
			cin>>c[i][j];
			if(c[i][j]==0) {
				pos=j;
			}
		}
		for(int j=1; j<=n; j++) {
			if(j==pos)continue;
			a[++cnt]= {j,pos,c[i][j]};
		}
	}
	sort(a+1,a+cnt+1,cmp);
	int sides=0;
	ll ans=0;
	for(int i=1; i<=cnt; i++) {
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx==fy)continue;
		fa[fx]=fy;
		ans+=a[i].w;
		sides++;
		if(sides==n-1) {
			cout<<ans;
			break;
		}
	}
	return 0;
}
