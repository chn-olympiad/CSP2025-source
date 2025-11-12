#include <bits/stdc++.h>
using namespace std;
struct road{
	long long u, v, c;
	operator < (road b){
		return c < b.c;
	}
};
const long long maxn  = 10000;
vector<long long> build_cost;
vector<vector<road> > bonus_roads;
vector<road> bonus_base;
vector<road> starters;//starting roads
long long og_n;
long long k;
struct one_way_tree{
	vector<long long> f;
	vector<long long> id;
	long long n;
	long long init(long long len){
		n = len;
		f.resize(n);
		id.resize(n);
		for(long long i = 0; i < n; i ++){
			f[i] = i;
			id[i] = i;
		}
	}
	long long find(long long i){
		if(f[i] == i) return i;
		long long j = find(f[i]);
		f[i] = j;
		return j;
	}
	long long connect(long long i, long long j){
		
		i = find(i);
		j = find(j);
		if(i != j){
		
		f[i] = j;
	}
	}
	bool connected(long long i, long long j){
		return find(i) == find(j);
	}
};
long long run(vector<road> a, long long n, long long m, long long k){
	one_way_tree ont;
	sort(a.begin(),a.end());
	ont.init(n + k);
	long long cost =0;
	for(long long i = 0; i < m; i++){
		if (not ont.connected(a[i].u,a[i].v)){
			long long u, v;
			u = a[i].u;
			v = a[i].v;
			ont.connect(u,v);
			cost += a[i].c;
		}
	}
	return cost;
}
long long merge(vector<road>& a, vector<road> b){
	for(long long i = 0; i< b.size(); i++){
		a.push_back(b[i]);
	}
	return 0;
}
int main(){
	vector<road> ar(6);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n, m, k;
	cin>>n>>m>>k;
	road tj{0, 0, 0};
	bonus_base.resize(n,tj);
	bonus_roads.resize(k,bonus_base);
	build_cost.resize(k);
	starters.resize(m);
	for(long long i = 0; i < m; i ++){
		long long a, b, c;
		cin>>a>>b>>c;
		a--;
		b--;
		starters[i].u = a;
		starters[i].v = b;
		starters[i].c = c;
	}
	
	for(long long i = 0; i < k; i ++){
		cin>>build_cost[i];
		for(long long j = 0; j < n; j++){
			long long c;
			cin>>c;
			road tmp{i+n, j, c};
			bonus_roads[i][j] = tmp;
		}
	}
	vector<bool> draft(k);
	vector<bool> optimal_draft(k);
	vector<bool> prev_draft(k,false);
	long long cost;
	long long optimal_cost;
	long long optimal_id;
	bool flag = true;
	vector<bool> flagged(k,false);
	vector<road> optimal_roads;
	vector<road> roads;
	long long base_cost = 0;
	while(flag){
		roads = starters;
		flag = false;
		draft = prev_draft;
		optimal_draft = prev_draft;
		optimal_id = 0;
		cost = run(roads, n, m, k);
		cost += base_cost;
		optimal_cost = cost;
		optimal_id = -1;
		optimal_roads = roads;
		for(long long i = 0; i < k; i ++){
			if(not prev_draft[i]){
			
			merge(roads,bonus_roads[i]);
			m += n;
			draft[i] = true;
			cost = build_cost[i];
			cost += run(roads,n,m,k);
			if (cost <=optimal_cost){
				flag = true;
				optimal_cost = cost;
				optimal_roads = roads;
				optimal_draft = draft;
				optimal_id = i;
				
			}
			draft[i] = false;
			m-= n;
			roads = starters;
			}
		}
		if (optimal_id != -1){
			flag = true;
			prev_draft = optimal_draft;
			starters = optimal_roads;
			m += n;
			base_cost += build_cost[optimal_id];
		}
	}
	cout<<optimal_cost;
	return 0;
}