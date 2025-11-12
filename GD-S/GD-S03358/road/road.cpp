#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct edge{
	int u,v,w;
}e[1000100];
int c[21];
int a[21][20010];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
vector<edge> ee;
int f[20010];
int find(int x){
	if(f[x] == x)return x;
	return f[x] = find(f[x]);
}
void hb(int u,int v){
	f[find(u)] = find(v);
	return;
}
int mx;
int kr(){
	vector<edge> tmp;
	for(edge ad:ee){
		tmp.push_back(ad);
	}
	int cc = 0,cal=0;
	for(int i = 1;i <= k;i++){
		if(c[i] == 0){
			cc++;
			for(int j = 1;j <= n;j++){
				tmp.push_back({n+i,j,a[i][j]});
			}
		}
	}
	sort(tmp.begin(),tmp.end(),cmp);
	int ans = 0;
	for(int i = 1;i <= 2*n;i++){
		f[i] = i;
	}
	int tot = 0;
	for(edge vv:tmp){
		int u = vv.u,v = vv.v,w = vv.w;
		if(find(u)!=find(v)){
			hb(u,v);
			ans+=w;
			tot++;
			if(tot == cc+n-1)break;
		}
	}
	return ans+cal;
}
int aans = 1e18;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		ee.push_back(e[i]);
	}
	for(int i = 1;i <= k;i++){
		cin>>c[i];
		for(int j = 1;j <= n;j++){
			cin>>a[i][j];
		}
	}
	cout<<kr();
	return 0;
} 
