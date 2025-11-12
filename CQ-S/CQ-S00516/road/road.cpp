#include<bits/stdc++.h>
using namespace std;
namespace cqsunny{
	int n, m, kr;
	struct node{
		int x, y, z;
	}a[1000010], a2[1000010];
	int b[100310];
	int d[12][100010];
	int u[100310];
	bool cmp(node p, node q){
		return p.z < q.z;
	}
	int get_father(int x){
		if(u[x] == x) return x;
		return u[x] = get_father(u[x]);
	}
	int main(){
		scanf("%d %d %d", &n, &m, &kr);
		for(int i = 1; i <= m; ++ i){
			scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
		}
		sort(a + 1, a + m + 1, cmp);
		m = min(m, 500000);
		for(int i = 1; i <= n; ++ i){
			u[i] = i;
		}
		int cnt = 0;
		long long ans = 0;
		for(int i = 1; i <= m; ++ i){
			if(cnt == n - 1) break;
			int t1 = get_father(a[i].x), t2 = get_father(a[i].y);
			if(t1 == t2) continue;
			u[t1] = t2;
			ans += a[i].z;
			++ cnt;
		}
		for(int i = 1; i <= kr; ++ i){
			scanf("%d", &b[i]);
			for(int j = 1; j <= n; ++ j){
				scanf("%d", &d[i][j]);
			}
		}
		int tot = 0;
		for(int i = 1; i <= kr; ++ i){
			int rr = 0; 
			for(int j = 1; j <= n; ++ j){
				a2[++ tot] = {i + n, j, d[i][j]};
			}
		} 
		sort(a2 + 1, a2 + tot + 1, cmp);
		tot = min(tot, 600000);
		int t = (1 << kr) - 1;
		for(int i = 1; i <= t; ++ i){
			for(int j = 1; j <= n; ++ j){
				u[j] = j;
			}
			for(int j = 1; j <= kr; ++ j){
				u[n + j] = n + j;
			}
			int fl[12] = {0}, ll = 0;
			long long sum = 0;
			for(int j = 0; j < kr; ++ j){
				if((i >> j) & 1){
					fl[j + 1] = 1;
					sum += b[j + 1];
					++ ll;
				}
			} 
			if(sum >= ans){
				continue;
			}
	//		if(i == 1){
	//			printf("%d %d %d\n", sum, fl[1], fl[2]);
	//		}
			int cnt = 0, ps = 1, tt = ll + kr;
			for(int j = 1; j <= m; ++ j){
				if(cnt == tt - 1 || sum >= ans){
					break;
				}
				while(ps <= tot && a2[ps].z <= a[j].z){
					if(cnt == tt - 1){
						break;
					}
					if(a2[ps].x <= n + kr && !fl[a2[ps].x - n]){
						++ ps;
						continue;
					} 
					int u1 = get_father(a2[ps].x), u2 = get_father(a2[ps].y);
					if(u1 == u2){
						++ ps;
						continue;
					} 
					++ cnt;
					sum += a2[ps].z;
					u[u1] = u2;
					++ ps;
	//				if(i == 1){
	//					printf("%d %d %d %d\n", ps, a2[ps].x, a2[ps].y, a2[ps].z);
	//				}
				}
				int u1 = get_father(a[j].x), u2 = get_father(a[j].y); 
				if(u1 == u2) continue;
				++ cnt;
				sum += a[j].z;
				u[u1] = u2;
	//			if(i == 1){
	//				printf("%d %d %d\n", a[j].x, a[j].y, a[j].z);
	//			}
			}
			ans = min(ans, sum);
	//		printf("%d %lld\n", i, sum); 
		}
		printf("%lld", ans);
		return 0;
	}
} 
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	return cqsunny::main();
}
