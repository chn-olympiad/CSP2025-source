#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
struct node{
	int u,v;
	ll w;
};
vector<node> mp;
int t[100010];
ll e[100010];

int find(int x){
	if(t[x] != x) return t[x] = find(t[x]);
	return x;
}

bool cmp(node x,node y){
	return x.w < y.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		mp.push_back({u,v,w});
	}
	for(int i = 1;i <= n;i++){
		t[i] = i;
	}
	for(int i = 1;i <= k;i++){
		ll c;
		cin>>c;
		for(int i = 1;i <= n;i++){
			cin>>e[i];
		}
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				mp.push_back({i,j,e[i] + e[j] + c});
			}
		}
	}
	ll ans = 0;
	sort(mp.begin(),mp.end(),cmp);
	for(int i = 0;i < mp.size();i++){
		int u = mp[i].u,v = mp[i].v,w = mp[i].w;
		int uu = find(u) ,vv = find(v);
		if(uu != vv){
			ans += w;
			t[uu] = t[vv];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

