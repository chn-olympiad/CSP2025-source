#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+10;
int a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;;
		cin>>v>>u>>w;
	}
	for(int i=1;i<=n+1;i++){
		cin>>a[i];
	}
	ll ans=0;
	sort(a+1,a+n+1+1);
	for(int i=1;i<=n;i++){
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}
