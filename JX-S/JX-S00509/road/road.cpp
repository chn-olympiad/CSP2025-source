#include <bits/stdc++.h>
using namespace std;
const int M = 2 * 1e6 + 10,N = 1e3 + 15;
int t,n,m,k,a[N][15],b[N][N],tot = 0,h[M],fa[N],deg[N],minn[N][15],c[N],bian[N][N];
struct edge {
	int u,v,w;
};
vector<edge> V;
int get(int x) {
	if(fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}
void merge(int x,int y) {
	fa[get(x)] = get(y);
}
void add(int u,int v,int w) {
	//e[++tot] = {v,w,h[u]};
	//h[u] = tot;
	edge t;
	t.u = u,t.v = v,t.w = w;
	V.push_back(t);
}
bool cmp (edge a,edge b) {
	 return a.w < b.w;
}
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  cin >> n >> m >> k;
  for(int i = 1; i <= m; i++) {
	  int u,v,w;
	  cin >> u >> v >> w;
	  add(u,v,w);
 }
 int f = 0;
 for(int i = 1; i <= k; i++) {
	 cin >> c[i];
	 if(c[i] != 0) f = 1;
	  for(int j = 1; j <= n; j++) {
		  cin >> a[j][i];
	  }
  } 
  long long res  = 1e9;
  if(f == 0) {
	   vector<edge> V2;
	   V2 = V;
	   long long ans = 0,cnt = 0;
	   for (int i = 1; i <= k; i++){
				for(int j = 1; j <= n; j++) {
					for(int l = j + 1; l <= n; l++) {
						edge t;
	                 t.u = j,t.v = l,t.w = a[j][i] + a[l][i];
	                 V2.push_back(t);
				  }
				  
				  
			   }
			   ans += c[i];
			   cnt++;
	}
		sort(V2.begin(),V2.end(),cmp);
		for(int i = 1; i <= n; i++) fa[i] = i;
	   for(int i = 0; i < V2.size(); i++) {
	      int u = V2[i].u,v = V2[i].v,w = V2[i].w;
	      if(u > v) swap(u,v);
	      if(get(u) != get(v)) {
			  ans += w;
			  merge(u,v);
			  deg[u]++;
			  deg[v]++;
			 }
       }
	cout << ans << '\n';
	}  else if(k <= 5 && n <= 1e3) {  
  for(int idx = 0; idx < (1 << k); idx++) {
	   vector<edge> V2;
	   V2 = V;
	   long long ans = 0,cnt = 0;
	    for(int i = 1; i <= k; i++) {
			if(idx & (1 << (i - 1))) {
				for(int j = 1; j <= n; j++) {
					for(int l = j + 1; l <= n; l++) {
						edge t;
	                 t.u = j,t.v = l,t.w = a[j][i] + a[l][i];
	                 V2.push_back(t);
				  } 
			   }
			   ans += c[i];
			   cnt++;
			}
		} 
		sort(V2.begin(),V2.end(),cmp);
		for(int i = 1; i <= n; i++) fa[i] = i;
	   int e = 0;
	   for(int i = 0; i < V2.size(); i++) { 
	      int u = V2[i].u,v = V2[i].v,w = V2[i].w;
	      if(u > v) swap(u,v);
	      if(get(u) != get(v)) {
			  ans += w;
			  e++;
			  merge(u,v);
			  deg[u]++;
			  deg[v]++;
			 }
			 if(e == n - 1) break;
        }
       res = min(res,ans);
	}
	cout << res << '\n';
	}

  return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
