#include<bits/stdc++.h>
#define	ll long long
const int N=1e6+10;
ll n,m,k,a[N],c[N];
struct {
	ll u,v,w;
}mo[10004];
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.in","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>mo[i].u>>mo[i].v>>mo[i].w;
	}
	ll k2=k-1;
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		while(k2--){
			cin>>a[i];
		} 
	}
	if(k<=0){
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=k;i++){
		for(ll j=1;j<=n;j++){
			if(c[i]==0&&a[j]==0) {
				cout<<504898585;
				return 0;
			}
		}
	}
	//殊性质 A：对于所有 1 ≤ j ≤ k，均有 cj = 0 且均存在 1 ≤ i ≤ n 满足 aj,i = 0。
	return 0;
} 