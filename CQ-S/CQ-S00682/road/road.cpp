#include <bits/stdc++.h>
#define ll long long
#define L(name, start, end) for (int name = start; name <= end; ++name)
#define R(name, start, end) for (int name = start; name >= end; --name)
using namespace std;

constexpr int N = 10005;
namespace mains{
	int n, m, k;
	int fa[N];
	struct edge{
		int u, v, w;
		bool operator < (const edge & tmp) const {
			return w < tmp.w;
		}
	};
	int find(int u){
		if (fa[u] == u)return u;
		return fa[u] = find(fa[u]);
	}
	vector<edge> vec, vec2;
	vector<int>trys;
	map<pair<int,int>,int> flag;
	int used[N], sel[N], tp[N];
	int run(int test) {
		memset(used, 0, sizeof used);
		vec.clear(), vec2.clear();
		cin >> n >> m >> k;
		L(i, 1, n) fa[i] = i;
		L(i, 1, m){
			int u, v, w;
			cin >> u >> v >> w;
			vec.push_back({u, v, w});
		}
		sort(vec.begin(), vec.end());
		int answer = 0;
		L(i, 0, m - 1) {
			int u = vec[i].u, v = vec[i].v, w = vec[i].w;
			u = find(u), v = find(v);
			if (u != v) {
				vec2.push_back(vec[i]);
				answer += w;
				fa[v] = u;
			}
		}
		sort(vec2.begin(), vec2.end());
		int size = vec2.size();
		bool flag2 = 0;
		L(i, 1, k) {
			cin >> sel[i];
			bool flagt = 1;
			if (sel[i]) flagt = 0;
			L(j, 1, n) {
				cin >> tp[j];
				if(tp[j]) flagt = 0;
			}
			if (flagt) {
				flag2 = 1;
				break;
			}
			trys.clear();
			int smaller = 0;
			R(t, size - 1, 0) {
				int u = vec2[t].u, v = vec2[t].v, w = vec2[t].w;
				if (tp[u] + tp[v] < w) {
					smaller += w - tp[u] - tp[v];
					trys.push_back(t);
				}
			}
//			cout << "[debug]" << i << ' ' << sel[i] << ' ' << smaller << '\n';
			if (smaller > sel[i]) {
				for (auto id : trys) {
					int u = vec2[id].u, v = vec2[id].v;
					if (flag[{u, v}]) {
						used[flag[{u, v}]]--;
						if (used[flag[{u, v}]] == 0) {
							answer -= sel[flag[{u, v}]];
						}
					}
					flag[{u, v}] = i;
					vec2[id].w = tp[u] + tp[v];
					++used[i];//使用次数 
				}
				answer = answer + sel[i] - smaller;
			}
		}
		if(flag2) cout << 0;
		else cout << answer;
		return 0;
	}
}using namespace mains;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T = 1;
//	cin >> T;
	L(i, 1, T){
		run(i);
	}

	return 0;
}

