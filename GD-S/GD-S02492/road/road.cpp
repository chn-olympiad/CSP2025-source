#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct road{
	int u,v,f,typ;
}v[1000010];

ll cost,c[10],fa[10010];

int f(int k){
	if(fa[k]==k) return k;
	else return fa[k]=f(fa[k]);
}

void solve(){
	int cost=;
	sort(v+1,v+1+n,cmp);
	queue<int> q;push();
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>v[i].u>>v[i].v>>v[i].w;
	}
	int cnt=m;
	for(int i=1;i<=m;i++){
		cin>>c[i];
		cost+=c[i];
		for(int j=1;j<=n;j++){
			cin>>;
		}
	}
	solve();
	return 0;
}
