#include<bits/stdc++.h>
using namespace std; 
const int N=1e4+5;
const int M=1e6+5;
long long n,m,k,ans;
int u[N],v[N],w[M],c[11],a[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		if(m<n) ans+=w[i];
		
	}
	for(int i=1;i<=k;i++){
		cin>>c[i]>>a[i];
	}
	cout<<ans;
	return 0;
}