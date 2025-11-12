#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node {
	int x,y,z;
} a[1000010],aa[100010],b[2000010];
int fa[100020],neww[20][10010];
int get(int x) {
	if (x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
bool cmp(node c,node d) {
	return c.z<d.z;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	for (register int i=1; i<=m; ++i) {
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for (register int i=1; i<=n; ++i) {
		fa[i]=i;
	}
	sort(a+1,a+1+m,cmp);
	int lll=0;
	for (register int i=1; i<=m; ++i) {
		if (lll==n-1) {
			break;
		}
		int x=a[i].x,y=a[i].y,z=a[i].z;
		int xx=get(x),yy=get(y);
		if (xx==yy) continue;
		fa[xx]=yy;
		aa[++lll].x=x;
		aa[lll].y=y;
		aa[lll].z=z;
	}
	for (register int i=1; i<=lll; ++i) {
		b[i].x=aa[i].x;
		b[i].y=aa[i].y;
		b[i].z=aa[i].z;
	}
	for (register int i=1; i<=k; ++i) {
		for (register int j=0; j<=n; ++j) {
			cin>>neww[i][j];
		}
	}
	for (register int i=1; i<=n+k; ++i) {
		fa[i]=i;
	}
	int ans=0;
	for (register int i=1; i<=k; ++i) {
		ans+=neww[i][0];
		for (int j=1; j<=n; ++j) {
			b[++lll].x=n+i;
			b[lll].y=j;
			b[lll].z=neww[i][j];
		}
	}
	sort(b+1,b+1+lll,cmp);
	int llll=0;
	for (register int i=1; i<=lll; ++i) {
		if (llll==n+k-1){
			break;
		}
		int x=b[i].x,y=b[i].y,z=b[i].z;
		int xx=get(x),yy=get(y);
		if (xx==yy) continue;
		fa[xx]=yy;
		ans+=z;
		++llll;
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
*/
