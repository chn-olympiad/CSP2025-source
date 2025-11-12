#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const int N = 1e5 + 10;
int n;
struct info {
	int x, y, z, p, id;
} v[N], g[N];
pair<int, int> a[N], b[N], c[N];

int per[207][207] = {
{0,0,0,0},
{0,1,1,1},
{0,1,1,2},
{0,1,1,3},
{0,1,2,1},
{0,1,2,2},
{0,1,2,3},
{0,1,3,1},
{0,1,3,2},
{0,1,3,3},
{0,2,1,1},
{0,2,1,2},
{0,2,1,3},
{0,2,2,1},
{0,2,2,2},
{0,2,2,3},
{0,2,3,1},
{0,2,3,2},
{0,2,3,3},
{0,3,1,1},
{0,3,1,2},
{0,3,1,3},
{0,3,2,1},
{0,3,2,2},
{0,3,2,3},
{0,3,3,1},
{0,3,3,2},
{0,3,3,3},
};

bool cmp1(const info &a, const info &b) {return a.x > b.x;}
bool cmp2(const info &a, const info &b) {return a.y > b.y;}
bool cmp3(const info &a, const info &b) {return a.z > b.z;}

inline void into() {
	sort(g + 1, g + n + 1, cmp1);rep(i, 1, n) a[i].first = g[i].x, a[i].second = g[i].id;
	sort(g + 1, g + n + 1, cmp2);rep(i, 1, n) b[i].first = g[i].y, b[i].second = g[i].id;
	sort(g + 1, g + n + 1, cmp3);rep(i, 1, n) c[i].first = g[i].z, c[i].second = g[i].id;
}

int f() {
	int ans = 0;
	for (int l = 1; l <= 27; l++) {
		int res = 0;
		int len[4]={0,0,0,0};
		for (int i = 1; i <= n; i++) v[i].p = 0;
		for (int j = 1, k = n; k != 0; j++, k--) {
			if (j == 4) j = 1;
			if (per[l][j] == 1 && len[1] < n / 2) {
				for (int i = 1; i <= n; i++){
					if (!v[a[i].second].p){
						len[1]++, v[a[i].second].p = 1, res += a[i].first; break;
					}
				}
			} if (per[l][j] == 2 && len[2] < n / 2) {
				for (int i = 1; i <= n; i++){
					if (!v[b[i].second].p){
						len[2]++, v[b[i].second].p = 1, res += b[i].first; break;
					}
				}
			} if (per[l][j] == 3 && len[3] < n / 2) {
				for (int i = 1; i <= n; i++){
					if (!v[c[i].second].p){
						len[3]++, v[c[i].second].p = 1, res += c[i].first; break;
					}
				}
			}
		}
		ans = max(ans, res);
	}
	return ans;
}


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int _;
	scanf("%d", &_);
	for (; _--; ) {
		int ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].z);
			v[i].id = i, v[i].p = 0;
			g[i].x = v[i].x, g[i].y = v[i].y, g[i].z = v[i].z;
			g[i].id = i, g[i].p = 0;
		}
		into();
		printf("%d\n", f());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
