#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mk make_pair
#define fir first
#define sec second
const int MX = 1e6 + 7;
const ll INF = 1e18 + 7;
int u[MX],v[MX],id[MX];ll w[MX];
vector<int > ids;
ll c[15];pair<ll,int > a[15][10005];
int fa[MX];int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
struct Edge{
	int x,y;ll val;
};
int read(){
	int x = 0,ch = getchar();
	while(!(ch >= 48 && ch <= 57))ch = getchar();
	while(ch >= 48 && ch <= 57)x = x * 10 + ch - 48,ch = getchar();
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;n = read();m = read();k = read();
	for(int i = 1;i <= m;i++){u[i] = read();v[i] = read();w[i] = read();}
	for(int i = 0;i < k;i++){
		c[i] = read();
		for(int j = 1;j <= n;j++){a[i][j].fir = read();a[i][j].sec = j;}
		sort(a[i] + 1,a[i] + 1 + n);
	}
	for(int i = 1;i <= m;i++)id[i] = i;
	for(int i = 1;i <= n;i++)fa[i] = i;
	sort(id + 1,id + 1 + m,[&](int x,int y){return w[x] < w[y];});
	for(int it = 1;it <= m;it++){
		int i = id[it];
		if(find(u[i]) != find(v[i])){
			int uu = find(u[i]),vv = find(v[i]);
			fa[uu] = vv;ids.push_back(i);
		}
	}
	ll ans = INF;
	for(int s = 0;s < 1 << k;s++){
		ll sum = 0;
		vector<Edge > E;
		for(int i = 0;i < k;i++)
			if((s >> i) & 1){
				sum += c[i];
				int p = 0;
				vector<Edge > nE; 
				for(int j = 1;j <= n;j++){
					while(p < E.size() && E[p].val < a[i][j].fir){nE.push_back(E[p]);p++;}
					nE.push_back((Edge){n + i + 1,a[i][j].sec,a[i][j].fir});
				}
				while(p < E.size()){nE.push_back(E[p]);p++;}
				E = nE;nE.clear();
			}
		int p = 0;vector<Edge > nE;
		for(auto it : ids){
			while(p < E.size() && E[p].val < w[it]){nE.push_back(E[p]);p++;}
			nE.push_back((Edge){u[it],v[it],w[it]});
		}
		while(p < E.size()){nE.push_back(E[p]);p++;}
		E = nE;nE.clear();
		for(int i = 1;i <= n + k;i++)fa[i] = i;
		for(auto it : E){
			if(find(it.x) != find(it.y)){
				int xx = find(it.x),yy = find(it.y);
				fa[xx] = yy;sum += it.val;
			}
		}
		ans = min(ans,sum);
	}
	cout << ans << '\n';
	return 0;
}