#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+10;
struct place{
	bool city;
	bool lighted;
};
vector<int> light;
struct road{
	int v;
	int w;
};
vector<road> r[MAXN];
int minu,minv;
int minw = 1e9+10;
int c[110];
place p[MAXN];
int ans;
int n,m,k;
void solve(){
	p[1].lighted=true;
	p[1].city=true;
	light.push_back(1);
	int lightedcity = 1;
	while(lightedcity<n){
		for(auto cur:light){
			for(auto v:r[cur]){
				if(v.v>n) p[v.v].city=false;
				else p[v.v].city=true;
				if (p[v.v].lighted==false){
					if(p[v.v].city==false){
						if(v.w + c[v.v-n] < minw){
							minw = v.w+c[v.v-n];
							minv = v.v;
						}
					}
					else if(v.w < minw){
						minw = v.w;
						minv = v.v;
					}
				}
			}
		}
		p[minv].lighted=true;
		if(p[minv].city) lightedcity++;
		light.push_back(minv);
		ans+=minw;
		minw = 1e9+10;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		road note;
		note.v=v;
		note.w=w;
		r[u].push_back(note);
		note.v=u;
		r[v].push_back(note);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int a;
			road note;
			cin>>a;//代表到j号城市的费用 
			note.v=j;
			note.w=a;
			
			r[n+i].push_back(note);
			note.v=n+i;
			r[j].push_back(note);
		}
	}
	solve();
	cout<<ans;
	return 0;
}
