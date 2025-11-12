#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
const int N=1e6+5;
int u[N],v[N],w[N];
int c[N],a[N],a2[N]; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i]>>a[i]>>a2[i];
	}
	for(int i=1;i<=m;i++){
		ans+=u[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
