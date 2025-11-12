#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000010],v[1000010],w[1000010],c[20],a[20][10010],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++) cin>>a[i][j];
	}
	if(k==0){
		for(int i=0;i<m;i++) ans+=w[i];
	}
	cout<<ans;
	return 0;
}
