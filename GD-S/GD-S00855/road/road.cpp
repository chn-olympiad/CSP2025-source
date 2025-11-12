//T2(100)
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int N = 10100, M = 1000100;

int n, m, K, C[20];//乡镇从0开始编号 
ll ans;

int p[N];//并查集中，乡镇从n+1到n+K编号 
int fnd(int x){
	return (x == p[x] ? x : p[x] = fnd(p[x]));
}
void unn(int x, int y){
	p[fnd(x)] = fnd(y);
}

struct Edge{
	int u, v, w;
} e[M], a[20][N];
bool operator<(Edge x, Edge y){
	return x.w < y.w;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> K;
	for (int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 0; i < K; i++){//乡镇从0开始编号，在并查集中，乡镇从n+1开始编号 
		cin >> C[i];
		for (int j = 1, w; j <= n; j++)//并查集中是n+i+1 
			cin >> w, a[i][j] = {n + i + 1, j, w};
		sort(a[i] + 1, a[i] + n + 1);
	}
	
	stable_sort(e + 1, e + m + 1);
	int real = 0;//只有real条边是有效的（最后，real=n-1） 
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= m; i++)
		if (fnd(e[i].u) != fnd(e[i].v)){
			unn(e[i].u, e[i].v);
			e[++real] = e[i];
			ans += e[i].w;//ans为初始最小生成树权值和 
		}
	
	int pos, cur[20];//原本最小生成树的边考虑到pos，第i个乡镇的边考虑到cur[i] 
	for (int s = 1; s < (1 << K); s++){
		ll res = 0;
		vector<int> G;
		multiset<Edge> st;//不是multiset也没关系，重边只需考虑一次（st中最多11个元素，不会爆内存） 
		
		pos = 1, st.insert(e[1]);
		for (int i = 0; i < K; i++)
			if ((s >> i) & 1){
				res += C[i];
				cur[i] = 1;
				st.insert(a[i][1]);
				G.push_back(i);
				p[n + i + 1] = n + i + 1;//并查集初始化 
			}
		//并查集初始化 
		for (int i = 1; i <= n; i++)
			p[i] = i;
		
		for (int k = 1; k < n + (int)G.size(); k++){//n+G.size()-1次连边 
			Edge now = *st.begin();
			res += now.w, unn(now.u, now.v);
			if (pos <= n - 1 && fnd(e[pos].u) == fnd(e[pos].v)){
				st.erase(st.find(e[pos]));
				while (pos <= n - 1 && fnd(e[pos].u) == fnd(e[pos].v))
					pos++;
				if (pos <= n - 1)
					st.insert(e[pos]);
			}
			for (int i : G){
				if (cur[i] <= n && fnd(a[i][cur[i]].u) == fnd(a[i][cur[i]].v)){
					st.erase(st.find(a[i][cur[i]]));
					while (cur[i] <= n && fnd(a[i][cur[i]].u) == fnd(a[i][cur[i]].v))
						cur[i]++;
					if (cur[i] <= n)
						st.insert(a[i][cur[i]]);
				}
			}
		}
		
		ans = min(ans, res);
	}
	cout << ans << "\n";
	return 0;
}
