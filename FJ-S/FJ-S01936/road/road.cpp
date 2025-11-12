#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k;
int u[N],v[N],w[N],c[N],a[N][N];
int ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++) cin>>a[i][j];
	}
	cout<<ans;
	return 0;
}
