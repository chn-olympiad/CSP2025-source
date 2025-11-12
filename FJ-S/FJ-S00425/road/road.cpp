#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[100001],fa[100001],ans=0,sum=0,jl[100001];
struct V {
	int x,y,z;
} a[1000100];
bool cmp(V a,V b) {
	return a.z<b.z;
}
int find(int x) {
	if(x!=fa[x])return find(fa[x]);
	return x=fa[x];
}
int main() {
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1; i<=100001; i++)fa[i]=i;
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)cin>>a[i].x>>a[i].y>>a[i].z;
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		jl[i]=jl[i-1]+c[i];
		for(int j=1,z; j<=n; j++){
		cin>>z,a[n+i+j-1].x=i+n,a[n+i+j-1].y=j,a[n+i+j-1].z=z;
		}
	}
	sort(a+1,a+1+n,cmp);
	sum=0x3f3f3f3f;
	for(int qwe=1; qwe<=n*k; qwe++) {
		sort(a+1,a+1+n+qwe,cmp);
		for(int i=1; i<=100001; i++)fa[i]=i;
		ans=jl[qwe/n];
		for(int i=1; i<=n+qwe; i++) {
			int xw=find(a[i].x);
			int yw=find(a[i].y);
			if(xw!=yw) {
				fa[xw]=yw;
				ans+=a[i].z;
			}
		}
		sum=min(sum,ans);
	}
	cout<<sum+1;
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/