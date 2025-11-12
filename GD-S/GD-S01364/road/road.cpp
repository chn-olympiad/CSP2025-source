#include<bits/stdc++.h>
#define up(i, a, b) for(int i = (int)a; i <= (int)b; ++i)
#define dn(i, a, b) for(int i = (int)a; i >= (int)b; --i)
#define vc vector
#define pb push_back
#define pii pair<int, int>
#define x first
#define y second
#define ll long long

using namespace std;

const int MN = 1e4 + 5;
const int Mm = 1e6 + 5;

int n, m, k;
struct edge{
	int x, y, z;
}p[Mm];
bool cmp(edge p1, edge p2){
	return p1.z < p2.z;
}
pii a[11][MN];
int c[11], tl[11];
int fa[MN];
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	up(i, 1, m){
		int x, y, z;
		scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
//		if(p[i].z < 100000) printf("FK: %d %d %d\n", p[i].x, p[i].y, p[i].z);
	}
	sort(p + 1, p + 1 + m, cmp);
	up(i, 1, k){
		scanf("%d", &c[i]);
		up(j, 1, n){
			scanf("%d", &a[i][j].x);
			a[i][j].y = j;
		}
		sort(a[i] + 1, a[i] + 1 + n);
	}
	ll ans = 1e18;
	for(int j = 0; j < (1 << k); ++j){
		up(i, 1, n) fa[i] = i;
		int cnt = 0, id = 1;
		ll res = 0;
		up(w, 1, k){
			if((1 << w - 1) & j){
				res += (ll)c[w] + a[w][1].x;
				tl[w] = 1;
			}
		}
		while(cnt < n - 1){
			up(w, 1, k){
				if((1 << w - 1) & j){
					while(tl[w] < n){
						if(a[w][tl[w] + 1].x >= p[id].z) break;
						tl[w]++;
						if(find(a[w][tl[w]].y) != find(a[w][1].y)){
							fa[find(a[w][tl[w]].y)] = find(a[w][1].y);
							res += a[w][tl[w]].x;
							cnt++;
						}
					}
				}
			}
			if(find(p[id].x) != find(p[id].y)){
				cnt++;
				res += p[id].z;
				fa[find(p[id].x)] = find(p[id].y);
			}
			id++;
		}
//		printf("FK: %d %lld %d\n", j, res, cnt);
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
	return 0;
}
