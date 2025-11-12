#include <bits/stdc++.h>
#define ll long long
using namespace std;
int m,n,k,u,v,w;
ll ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans;
}
