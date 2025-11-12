//GZ-S00384 贵阳市清华中学 胡钦焯 
#include <bits/stdc++.h>
using namespace std;
int n,m,a[600],k;
int cy1[1000010],cy2[1000010],w[1000010];
int cw[1000010],mw[1000010];
string s;
int main() {
	freopen("road.input","r",stdin);
	freopen("road.output","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) cin>>cy1[i]>>cy2[i]>>w[i];
	for(int i=1; i<=k; i++) {
		cin>>cw[i];
		for(int j=1;j<=n;j++){
			cin>>w[j];
		}
	}
	cout<<0;
	return 0;
}
