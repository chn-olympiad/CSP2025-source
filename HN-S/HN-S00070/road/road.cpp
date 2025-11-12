//inpresation111 's Code
#include<iostream>
#include<cstdio>
#define int long long
using  namespace std;
int n,m,k,ans;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans<<endl;
	return 0;
}

