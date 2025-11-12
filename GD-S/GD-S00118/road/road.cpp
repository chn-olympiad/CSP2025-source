#include <bits/stdc++.h>
using namespace std;
int a[1000006];
int b[1000006],bs;
int c[1000006];
int w[1000006];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u,v1;
		cin>>u>>v1;
		a[u]=v1;
		a[v1]=u;
		cin>>w[i];
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>b[i];
		}
	}
	int cnt=0,num=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==j) continue;
			if(cnt%(n-1)!=0) {
				//int num=0;
				num+=min(w[j],c[j]+b[j]);
				//cout<<num;
				//minn=min(minn,num);
			}
		}
	}
	cout<<num;
	return 0;
}
