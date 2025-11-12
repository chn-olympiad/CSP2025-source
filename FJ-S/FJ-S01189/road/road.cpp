#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, k;
struct edge{
	long long u, v, w;
	bool operator>(const edge& e) const{
		return w>e.w; 
	}
}a[1000010];
ll c[20], mp[20][10010];
priority_queue<edge, vector<edge>, greater<edge> > q;
ll f[10020];
vector<edge> medge;
ll find(ll x) {
	if(f[x] == x){
		return x;
	}
	return f[x] = find(f[x]);
}
void add(ll x, ll y){
	f[find(x)] = find(y);
}
void build(){
	for(int i=1;i<=n;i++){
		f[i] = i;
	}
	for(int i=1;i<=m;i++){
		q.push(a[i]);
	}
	int i=1;
	while(i<=n-1){
		edge tp = q.top();q.pop();
		if(find(tp.u) == find(tp.v)) continue;
		medge.push_back(tp);
		add(tp.u, tp.v);
		i++;
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
		}
	}
	build();
	long long ans = 1e18, s, len;
	for(int i=0;i<(1<<k);i++){
		s=0;
		len = n;
		for(int j=1;j<=k;j++){
			if(i & (1<<(j-1))){
				len++;
				s+=c[j];
				for(int e=1;e<=n;e++){
					q.push({len, e, mp[j][e]});
				}
			}
		}
		for(int j=0;j<medge.size();j++){
			q.push(medge[j]);
		}
		for(int j=1;j<=len;j++){
			f[j] = j;
		}
		int j=1;
		while(j<=len-1){
			edge tp = q.top();q.pop();
			if(find(tp.u) == find(tp.v)) continue;
			s += tp.w;
			add(tp.u, tp.v);
//			cout<<tp.u<<" "<<tp.v<<endl;
			j++;
		}
//		cout<<endl;
		ans = min(s, ans);
	}
	cout<<ans;
	return 0;
} 
