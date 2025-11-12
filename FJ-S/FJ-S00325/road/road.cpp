#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005];
long long sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	sort(w+1,w+1+n);
	for(int i=1;i<=n-1;i++){
		sum+=w[i];
	}
	cout<<sum;
	return 0;
}
