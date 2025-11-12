#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10010],b[10010],c[10010],d[20],e[20][10010],ans;
int main () {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++) {
		cin>>a[i]>>b[i]>>c[i];
		ans+=c[i];
	}
	for (int i=1;i<=k;i++) {
		cin>>d[i];
		for (int j=1;j<=n;j++) {
			cin>>e[i][j];
		}
	}
	cout<<ans;
	return 0;
}
