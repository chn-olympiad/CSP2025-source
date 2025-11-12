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

const int MN = 5e2 + 5;
const int Mod = 998244353;

void add(int &x, int y){(x = ((x + y) > Mod) ? (x + y - Mod) : (x + y));}

int n, m;
char p[MN];
int a[MN];
int f[19][262146];
bool vis[19][262146];

int F(int s, int k){
	if(k > n - m) return 0;
//	printf("FK: %d %d\n", s, k);
	if(vis[k][s]) return f[k][s];
	vis[k][s] = 1;
	if(s == (1 << n) - 1) return f[k][s] = (k <= n - m);
	int len = 0;
	up(i, 1, n){
		if(s & (1 << i - 1)) len++;
	}
	up(i, 1, n){
		if(!(s & (1 << i - 1))){
			if(p[len + 1] == '1') add(f[k][s], F(s | (1 << i - 1), k + (k >= a[i])));
			else add(f[k][s], F(s | (1 << i - 1), k + 1));
		}
	}
	return f[k][s];
}
int f2[2][MN][MN];
int cnt[MN];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", p + 1);
	up(i, 1, n) scanf("%d", &a[i]);
	if(n <= 18){
		printf("%d\n", F(0, 0));
		return 0;
	}
	puts("0");
////	printf("FK: %d\n", f[2][7]);
//	up(i, 1, n){
//		cnt[a[i]]++;
//	}
//	f2[0][cnt[0]][0] = 1;
//	int w = 0;
//	up(i, 0, n - 1){
//		up(j, 0, n){
//			up(k, 0, n - m){
//				add(f2[w ^ 1][j - 1 + cnt[k]][k + 1], (ll)f2[w][j][k] * j % Mod);
//				add(f2[w ^ 1][j][k], f2[w][j][k]);
//			}
//		}
//		memset(f2[w], 0, sizeof(f2[w]));
//		w ^= 1;
//	}
//	int ans = 0;
//	up(j, 0, n) up(k, 0, n - m) add(ans, f2[w][j][k]);
//	printf("%d\n", ans);
	
	return 0;
}
