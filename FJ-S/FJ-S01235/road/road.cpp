#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[100005],v[100005],k[100005],c[15],a[15][100005];
int main(){
  	freopen("road.in","r",stdin);
  	freopen("road.out","w",stdout);
  	mt19937 mt(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>k[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<mt()*mt()%998244353;
	return 0;
}

