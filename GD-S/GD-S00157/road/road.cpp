#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1.1e6 + 50,M = 1e4 + 50;
int read(){
	int a = 1,x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') a = -1;
		ch = getchar();
	} 
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return a * x;
}
struct Edge{
	int u,v,w;
	friend bool operator < (Edge a,Edge b){
		return a.w < b.w;
	}
}e[N];
int nw[15][M],ecnt;
int c[15];
int fa[M],siz[M];
int find(int x){
	if(x != fa[x]) fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int a,int b){
	int p = find(a),q = find(b);
	if(p == q) return;
	fa[p] = q;
	siz[q] += siz[p];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	clock_t bg = clock();
	int n = read(),m = read(),k = read();
	for(int i=1;i<=m;i++){
		e[i].u = read(),e[i].v = read(),e[i].w = read();
	}
	ecnt = m;
	bool f = true;
	for(int i=1;i<=k;i++){
		c[i] = read();
		bool ff = false;
		f &= c[i] == 0;
		for(int j=1;j<=n;j++){
			nw[i][j] = read();	
			e[++ecnt] = Edge({n + i,j,nw[i][j]});
			ff |= nw[i][j] == 0;
		}
		f |= ff;
	}
	ll res = 9e18;
	if(f){
		res = 0;
		vector<Edge> ne;
		int cnt = n + k;
		for(int j=1;j<=m;j++){
			ne.push_back(e[j]);
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				ne.push_back({n + i,j,nw[i][j]});
			}
		}
		for(int i=1;i<=cnt;i++){
			fa[i] = i;
		}
		sort(ne.begin(),ne.end());
		
		for(int i=0;i<ne.size();i++){
			if(find(ne[i].u) != find(ne[i].v)){
				res += ne[i].w;
				merge(ne[i].u,ne[i].v);
				if(siz[find(ne[i].u)] == cnt) break;
			}
		}
		cout<<res;
		return 0;
	}
	sort(e + 1,e + ecnt + 1);
/*	for(int i=0;i<(1 << k);i++){
		vector<Edge> ne;
		for(int j=1;j<=m;j++){
			ne.push_back(e[j]);
		}
		int cnt = n;
		ll sum = 0;
		for(int j=0;j<k;j++){
			if(i & (1 << j)){
				sum += c[j + 1];
				cnt++;
				for(int t=1;t<=n;t++){
					ne.push_back(Edge({cnt,t,nw[j + 1][t]}));
				}
			}
		}
		for(int i=1;i<=cnt;i++){
			fa[i] = i;
		}
		sort(ne.begin(),ne.end());
		
		for(int i=0;i<ne.size();i++){
			if(find(ne[i].u) != find(ne[i].v)){
				sum += ne[i].w;
				merge(ne[i].u,ne[i].v);
				if(siz[find(ne[i].u)] == cnt) break;
			}
		}
		res = min(res,sum);
	}*/
	for(int i=0;i<(1 << k);i++){
		Edge ne[N];
		int pos = 0;
/*		for(int j=1;j<=m;j++){
			ne[++pos] = e[j];
		}*/
		int cnt = n + k;
		ll sum = 0;
		for(int j=0;j<k;j++){
			if(i & (1 << j)){
				sum += c[j + 1];
/*				for(int t=1;t<=n;t++){
					ne[++pos] = (Edge({cnt,t,nw[j + 1][t]}));
				}*/
			}
		}
		for(int k=1;k<=ecnt;k++){
			if(e[k].u <= n || (i & (1 << (e[k].u - 1 - n)))){
				ne[++pos] = e[k];
//				cerr<<"!!! "<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<'\n';
			}
		}
		for(int i=1;i<=cnt;i++){
			fa[i] = i;
			siz[i] = 1;
		}
//		sort(ne + 1,ne + pos + 1);
		
		for(int i=1;i<=pos;i++){
			if(find(ne[i].u) != find(ne[i].v)){
			
				sum += ne[i].w;
				if(sum >= res) break;
				merge(ne[i].u,ne[i].v);
				if(siz[find(ne[i].u)] == cnt) break;
			}
		}
		res = min(res,sum);
	}
	cout<<res;
	clock_t ed = clock();
	cerr<<'\n'<<double(ed - bg) / CLOCKS_PER_SEC;
	return 0;
}
