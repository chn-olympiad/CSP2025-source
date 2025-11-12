#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000000+10],v[1000000+10],w[1000000+10];
int c[10+10],a[10+10][10000+10];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1; i<=k; i++){
		cin>>c[i];
		for(int j=1; j<=n; j++){
			cin>>a[i][j];
		}
	}
	
	if(c[i]==0){
		int ans=0x3f3f3f3f;
		for(int i=1; i<=k; i++){
			int num=c[i];
			//cout<<c[i]<<" ";
			for(int j=1; j<=n; j++){
				num+=a[i][j];
				//cout<<a[i][j]<<" ";
			}
			//cout<<endl;
			ans=min(num,ans);
		}
		cout<<ans;
	}
	return 0;
}
