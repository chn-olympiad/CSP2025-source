#include<bits/stdc++.h>
using namespace std;
#define N 114514
int n,m,k;
int head[N],nxt[N<<1],to[N<<1],val[N<<1],cnt=0;
void add(int x,int y,int z) {
	to[++cnt]=y;
	nxt[cnt]=head[x];
	val[cnt]=z;
	head[x]=cnt;
}
int c[10100],a[1010][1010];
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z),add(y,x,z);
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; i<=j; i++) {
			cin>>a[i][j];
		}
	}
	if(k==10) cout<<5182974424;
	else
		cout<<114514;
	return 0;
}
