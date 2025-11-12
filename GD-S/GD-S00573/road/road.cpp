#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,k;
struct road{
	ll u,v,w;
}r[1000010];
struct vill{
	ll c;
	ll v[1000010];
}vi[11];
int main(){
	feropen("road.in","r",stdin);
	feropen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	for(ll i=1;i<=k;i++){
		cin>>vi[i].c;
		for(int j=1;j<=m;j++){
			cin>>vi[i].v[j];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
