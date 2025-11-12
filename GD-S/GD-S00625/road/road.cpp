#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c[15],a[15][10010];
int tu[10010][10010];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>u>>v>>w;
		tu[u]=tu[v]=w;
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	int cnt=0;
	for(int i=1; i<=k; i++) {
		bool falg=false;
		if(c[i]==0) {
			for(int j=1; j<=n; j++) {
				if(a[i][j]!=0) {
					falg=true;
					break;
				}
			}
		}
		if(falg)cnt++;
	}
	if(cnt==0)cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
