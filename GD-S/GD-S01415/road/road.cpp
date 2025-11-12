#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
const int N = 23162;
int u[N],v[N],w[N],c[N],a[N][N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i]>>a[i][j];
		}	
	}
	if(k==0){
		for(int i=1;i<=m;i++){
			ans+=w[i];
		}
		cout<<ans;
	}
	return 0;
} 
