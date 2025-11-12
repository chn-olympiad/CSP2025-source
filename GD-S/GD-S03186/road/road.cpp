#include <iostream>
#include <set>
#include <vector>
#include <algorithm> 
#define int long long
using namespace std;
using pii=pair<int, int>; 

const int maxn=1e4+5; 
const int inf=1e15; 

int rd() {
	int x=0, f=1;
	char c=getchar(); 
	
	while ((c < '0' || c > '9') && c != '-') {
		c=getchar(); 
	}
	if (c=='-') f=-1; 
	else {
		x = c-'0'; 
	}
	c=getchar(); 
	while (c >='0' && c <= '9') {
		x *= 10;
		x += c-'0'; 
		c = getchar(); 
	}
	return x; 
}


struct edge{
	int a, b, c;
	bool operator<(const edge &other) const {
		if (c != other.c) return c<other.c; 
		return a<other.a; 
	}
};

int n, m, k; 
vector<edge> V; 
vector<edge> U; 
pii a[11][maxn]; 
int c[maxn]; 

set<edge> K; 

int bitcnt(int x) {
	int cnt=0;
	while(x){
		cnt++;
		x -= (x&-x); 
	}
	return cnt; 
}

int fa[maxn]; 
int father(int x) {
	if (fa[x] == x) return x;
	return fa[x] = father(fa[x]); 
}
void merge(int x, int y) {
	x = father(x), y=father(y);
	fa[x] = y; 
}

signed main() {
	
	freopen("road.in", "r", stdin); 
	freopen("road.out", "w", stdout); 
	
	int ans=inf; 
	
	n=rd();
	m=rd();
	k=rd(); 
	
	for (int i=1; i<=m; i++) {
		int a, b, c;
		a=rd();
		b=rd();
		c=rd(); 
		V.push_back({a, b, c}); 
		
	}
	sort(V.begin(), V.end()); 
	for (int i=1; i<=k; i++){
		cin >> c[i];
		for (int j=1; j<=n; j++) {
			cin >> a[i][j].first; 
			a[i][j].second = j; 
		}
		sort(a[i]+1, a[i]+1+n); 
		a[i][n+1].first = inf;  
	}
	
	for (int j=1; j<=n+k; j++) fa[j] = j; 
	
	ans=0; 
	for (auto it: V) {
		if (father(it.a) == father(it.b)) {
			continue; 
		}
		merge(it.a, it.b);
		U.push_back(it); 
		ans += it.c; 
	} 
	
	for (int i=1; i<(1<<k); i++){
		int tmp=0; 
	
		K.clear(); 
		
		for (int j=1; j<=k; j++) {
			if (i&(1<<(j-1))) {
				tmp += c[j]; 
				K.insert({j, 1, a[j][1].first}); 
			}
		}
		
		for (int j=1; j<=n+k; j++) fa[j] = j; 
		
		int cnt=-bitcnt(i), ite=0; 
		while (cnt < n-1) {
			
			int A, b, c; 
			if (K.empty() || U[ite].c < (*K.begin()).c) {
				A = U[ite].a;
				b = U[ite].b;
				c = U[ite].c;
				ite++; 
			} else {
				auto tp=*K.begin(); 
				K.erase(tp); 
				
				A=tp.a+n; 
				b=a[tp.a][tp.b].second; 
				c=tp.c; 
				
				if (tp.b < n) K.insert({tp.a, tp.b+1, a[tp.a][tp.b+1].first}); 
			}
			
			if (father(A) == father(b)) continue; 
			
			cnt++; 
			tmp += c; 
			merge(A, b); 
		}
		ans = min(ans, tmp); 
	}
	
	cout << ans << endl; 
	
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


