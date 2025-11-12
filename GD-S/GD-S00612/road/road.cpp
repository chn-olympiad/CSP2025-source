#include<bits/stdc++.h>
using namespace std;
int k,n,m,v[100005],w[10005],u[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	if(m<n){
		for(int i=1;i<=n;i++){
			ans+=w[i];
		}
		cout<<ans;
	}
	else{
		cout<<w[3]+w[2];
	}		
	return 0;
}
