#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int Maxn = 1e4+15, Maxm = 1e6+15, Maxk = 15;
const ll INF = INT64_MAX/2-5;

namespace Josh_zmf {

	int N, M, K, fa[Maxn], size[Maxn], c[Maxn];
//	struct E { int u, v, w; } e[Maxm], bian[Maxm], tmp1[Maxn], tmp2[Maxn*Maxk];
	struct E {
		int u, v, w; 
		bool operator < (const E &b) const { return w < b.w; }
	} e[Maxm], bian[Maxm], tmp1[Maxn*Maxk], tmp2[Maxn*Maxk], a[Maxk][Maxn];
	
	inline int find(int u) {
		return fa[u]==u ?u :fa[u]=find(fa[u]);
	}
	
	inline void Union(int u, int v) {
		u = find(u), v = find(v);
		if(u == v)	return ;
		if(size[u] < size[v])	swap(u, v);
		size[u] += size[v], fa[v] = u;
	}

	int main() {
		cin>> N>> M>> K;
		for(int i=1, u, v, w; i<=M; i++)	cin>> u>> v>> w, e[i] = {u, v, w};
		sort(e+1, e+1+M, [&](E &a, E &b) { return a.w < b.w; } );
		for(int i=1; i<=N; i++)	fa[i] = i, size[i] = 1;
		ll ans = 0;
		for(int i=1, cnt=0; i<=M and cnt<N-1; i++) {
			int u = find(e[i].u), v = find(e[i].v);
			if(u == v)	continue;
			Union(u, v), e[++cnt] = e[i], ans += e[i].w;
//			printf("Add_edge(%d, %d, %d)\n", e[i].u, e[i].v, e[i].w);
		}
		for(int i=1; i<=K; i++) {
			cin>> c[i];
			for(int j=1; j<=N; j++)	cin>> a[i][j].w, a[i][j].u = i+N, a[i][j].v = j;
			sort(a[i]+1, a[i]+1+N);
		}
		for(int S=(1<<K)-1; S; S--) {
			int num1 = N-1, num2 = 0, asdf=0; ll res = 0;
			for(int i=1; i<=N-1; i++)	tmp1[i] = e[i];
			for(int i=1; i<=K; i++) {
				if(!((S>>(i-1))&1))	continue;
				res += c[i];
//				for(int j=1; j<=N; j++) {
//					tmp2[++num] = a[i][j];
//				}
//				asdf++;
				if(asdf&1) {
					static E b[Maxn*Maxk]; memcpy(b+1, tmp1+1, num1*sizeof(E));
					std::merge(b+1, b+1+num1, a[i]+1, a[i]+1+N, tmp1+1), num1 += N;
				} else {
					static E b[Maxn*Maxk]; memcpy(b+1, tmp2+1, num2*sizeof(E));
					std::merge(b+1, b+1+num2, a[i]+1, a[i]+1+N, tmp2+1), num2 += N;
				}
				asdf++;
			}
//			stable_sort(tmp2+1, tmp2+1+num, [&](E &a, E &b) { return a.w < b.w; } );
//			stable_sort(tmp2+1, tmp2+1+num);
//			int tot = 0;
//			for(int i=1, j=1; i<=tot and j<=N-1; i++) {
//				if(i>tot or (j<=N-1 and tmp2[j].w<tmp1[i].w))	bian[++tot] = tmp2[j++];
//				else	bian[++tot] = tmp1[i++];
//			}
			std::merge(tmp1+1, tmp1+1+num1, tmp2+1, tmp2+1+num2, bian+1);
			int tot = num1 + num2;
//			printf("S:%d, res:%lld\n", S, res);
			for(int i=1; i<=N+K; i++)	fa[i] = i, size[i] = 1;
//			sort(bian+1, bian+1+tot, [&](E &a, E &b) { return a.w < b.w; } );
			for(int i=1, cnt=0; i<=tot and cnt<N+asdf-1; i++) {
				int u = find(bian[i].u), v = find(bian[i].v);
				if(u == v)	continue;
				Union(u, v), res += bian[i].w;
				if(res >= ans)	break;
//				printf("Add_edge(%d, %d, %d)\n", bian[i].u, bian[i].v, bian[i].w);
			}
			ans = min(ans, res);
		}
		cout<< ans<< '\n';
		return 0;
	}

}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	Josh_zmf::main();
//while(1);
	return 0;
}

// 33MB

