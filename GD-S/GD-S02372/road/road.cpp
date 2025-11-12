#include<bits/stdc++.h>
using namespace std;

long long  n,m,k;
long long  u[1111111],v[11111111],w[111111111],c[1111111],a[11111111]; 
long long  sum=0;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		sum+=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)	cin>>a[j];
		
	}
	cout<<sum;
	return 0;
}
