#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],ans=0;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w".stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	sort(w+1,w+n+1);
	for(int i=1;i<n;i++) ans+=w[i];
	cout<<ans;
	return 0;
}
