#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4+100;
int n,m,k,mp[15][N],c[15],ans = 1e18;
struct node{
	int u,v,w;
	friend bool operator<(node a,node b){
		return a.w<b.w;
	}
};
vector<node> rec,E,del;
class DSU{
public:
	int fa[N];
	void init(int n){
		for(int i=1;i<=n;i++) fa[i] = i;
	}
	int find(int x){
		if(fa[x]==x) return x;
		return fa[x] = find(fa[x]);
	}
}D;
int Kruskal(int tot,int starrail,int op){
	sort(E.begin(),E.end());
	D.init(starrail);
	int cnt = 0,ans = 0;
	for(node e:E){
		int fx = D.find(e.u),fy = D.find(e.v);
		if(fx==fy) continue;
		D.fa[fx] = fy;
		ans += e.w;
		if(op) rec.push_back(e);
		cnt++;
	}
	if(cnt==starrail-1) return ans;
	return -1;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("C:\\Users\\user\\Downloads\\csps\\down\\road\\road3.in","r",stdin);
//	freopen("C:\\Users\\user\\Downloads\\csps\\down\\road\\road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		E.push_back({u,v,w});
	}
	Kruskal(m,n,1);
	E.clear();
	for(node e:rec) E.push_back(e);
	m = n-1;
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>mp[i][j];
	}
	for(int i=0;i<(1<<k);i++){
		int res = 0,tot = m,starrail = n;
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				starrail++;
				res += c[j];
				for(int t=1;t<=n;t++){
					E.push_back({t,starrail,mp[j][t]});
					del.push_back({t,starrail,mp[j][t]});
				}
			}
		}
		ans = min(ans,res+Kruskal(tot,starrail,0));
		for(node e:del) E.erase(lower_bound(E.begin(),E.end(),e));
		del.clear();
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
*/