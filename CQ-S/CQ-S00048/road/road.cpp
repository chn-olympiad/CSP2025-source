#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)cin>>u>>v>>w,ans+=w;
	cout<<ans<<"\n";
	return 0;
}
