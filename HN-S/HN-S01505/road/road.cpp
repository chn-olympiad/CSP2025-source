#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#define N 10100
#define M 1000005
#define K 15
using std::cout;
using std::cin;
using std::vector;
struct line {
	int l,r,w;
	bool operator<(line b) {
		return w<b.w;
	}
};
vector<line>e;
bool vis[K];
int fa[N],c[N],a[K][N];
int n,m,k;
void UFSinit() {
	for(int i=1; i<=n; i++)
		fa[i]=i;
}
int rootof(int x) {
	return fa[x]==x?x:fa[x]=rootof(fa[x]);
}
void read() {
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back((line) {
			u,v,w
		});
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++)
			cin>>a[i][j];
	}
}
void solve1() {
	sort(e.begin(),e.end());
	int ans=0;
	for(int i=0; i<e.size(); i++) {
		int l=rootof(e[i].l),r=rootof(e[i].r),w=e[i].w;
		if(l!=r) {
			fa[l]=r;
			ans+=w;
		}
	}
	cout<<ans;
}
void solve2() {
	sort(e.begin(),e.end());
	int ans1=0,ans2=0;
	for(int i=0; i<e.size(); i++) {
		int l=e[i].l,L=rootof(l),r=e[i].r,R=rootof(r),w=e[i].w;
		if(L!=R) {
			int minn=0x3f3f3f3f;
			int bh=0;
			for(int j=1; j<=k; j++)
				if(minn>(vis[j]?0:c[j])+a[j][l]+a[j][r]) {
					minn=(vis[j]?0:c[j])+a[j][l]+a[j][r];
					bh=j;
				}
			if(w>minn) {
				vis[bh]=true;
				w=minn;
			}
			fa[L]=R;
			ans1+=w;
		}
	}
	cout<<ans1;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read();
	UFSinit();
	if(k==0)
		solve1();
	else
		solve2();
	return 0;
}
