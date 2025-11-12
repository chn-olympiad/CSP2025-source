#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[1000001];
	int b[1000001];
	int u[1000001];
	int v[1000001];
	int w[1000001];
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		
	}
	int c;
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++)
		cin>>a[i];
	}
	int ans=0;
	if(f==0){
		
		for(int i=1;i<=m;i++){
			ans+=v[i];
		}
		cout<<ans;
		
		
	}
	return 0;
} 
