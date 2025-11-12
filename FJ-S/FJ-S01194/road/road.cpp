#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		int c;cin>>c;
		for(int j=1;j<=n;j++){
			int x;cin>>x;
		}
	}
	cout<<ans<<endl;
	return 0;
}
