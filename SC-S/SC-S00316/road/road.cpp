#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,c[15],a[15][1005],ans,f[1005];
struct edge{
	int u,v,w;
}e[1005];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
bool vis[1005];
int find(int x){
	if(x==f[x]){
		return x;
	}
	f[x]=find(f[x]);
	return f[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	bool b=0;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int p=find(e[i].u),q=find(e[i].v);
		if(find(p)!=find(q)){
			ans+=e[i].w;
			vis[i]=1;
			f[find(p)]=f[find(q)];
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		b=b|c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			b=b|a[i][j]; 
		}
    }
    if(!b){
    	cout<<0;
    	return 0;
	}
    cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
  tttttttttttttttttt
ttttttttttttttttttttttt
ttttttttttttttttttttttt
ttttt                tt
ttt                  tt
tt    tttttt   tt  tttttt
ttttttt    tttt  ttt    t
tt    ttttt        tttttt
tt             t     tt
tt            tt     tt
tt                   tt
tt       ttttttttt   tt
tt                   tt
ttttttttttttttttttttttt

*/