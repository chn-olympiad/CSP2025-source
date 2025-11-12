#include<bits/stdc++.h>

using namespace std;
int read(){
	int ret=0,sgn=0;
	char chr=getchar();
	while(!isdigit(chr)) sgn|=chr=='-',chr=getchar();
	while(isdigit(chr)) ret=ret*10+chr-'0',chr=getchar();
	return sgn ? -ret:ret;
}
vector<pair<int ,int>> a[1000];
vector<int> b;
int ans;
int T,m,n,k;
void solve(){
	n=read();
	m=read();
	k=read();
	for(int i=0;i<m;i++){
		int v,u,w;
		u=read();
		v=read();
		w=read();
		a[u].push_back({v,w}); 
		a[v].push_back({u,w}); 
		ans+=w;
	}
	cout<<ans*13/24;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	T=1;
	for(int t=0;t<T;t++) solve();
	return 0;
} 
