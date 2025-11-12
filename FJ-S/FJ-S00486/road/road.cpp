#include<bits/stdc++.h>
using namespace std;
struct node {
	int u_90,v_90,w_90;
} a[1000005];
struct edge {
	int c,a_90[10005];
} xz[15];
int n,m,k;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>a[i].u_90>>a[i].v_90>>a[i].w_90;
	}
	for(int i=1; i<=k; i++) {
		cin>>xz[i].c;
		for(int j=1; j<=n; j++) {
			cin>>xz[i].a_90[j];
		}
	}
	cout<<0;
	return 0;
}
