#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int u[100005],v[100005],w[100005],c[100005],a[100005][15];
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(w+1,w+m+1);
	for(int i=1;i<=m;i++){
		ans=ans+w[i];
	}
	cout<<ans;
	return 0;
}
