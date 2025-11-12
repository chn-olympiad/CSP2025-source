#include<bits/stdc++.h>
using namespace std;
struct city{
	int u,v,w;
	int a,mi;
}c[114514];
int n,m,k;
bool cmp(city x,city y){
return x.w<x.w;	
}

void solve(){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>c[i].u>>c[i].v>>c[i].w;
	}
	for(int i=0;i<k;i++){
		cin>>c[i].a;
		for(int j=0;j<n;j++){
			cin>>c[j].mi;
		}
	}
	sort(c,c+m,cmp);
	int ans=0;
	for(int i=0;i<k;i++){
		ans+=c[k].w;
	}
	cout<<ans;
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	return 0;
}
