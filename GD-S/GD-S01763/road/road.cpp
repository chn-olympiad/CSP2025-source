#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,k,c,b[10010],ans;
struct node{
	ll u,v,w;
}a[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		ans+=a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++) cin>>b[j];
	}
	cout<<ans;
	return 0;
}
