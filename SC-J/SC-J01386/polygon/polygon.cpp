#include <bits/stdc++.h> 
#define ll long long 

using namespace std; 

const int N = 5005; 
const int mod = 998244353; 

int n; 
int a[N]; 
int f[2][N][4]; 
int ans; 
int nid, pid; 

signed main() {
	freopen("polygon.in", "r", stdin); 
	freopen("polygon.out", "w", stdout); 
	
	scanf("%d", &n); 
	for (int i = 1; i <= n; i++) scanf("%d", a + i); 
	
	sort(a + 1, a + n + 1); 
	
	f[0][0][0] = 1; 
	for (int i = 1; i <= n; i++) {
		nid = i & 1; 
		pid = nid ^ 1; 
		for (int j = a[i] + 1; j <= 5001; j++) ans = ((ans + f[pid][j][3]) % mod + f[pid][j][2]) % mod; 
		f[nid][0][0] = 1; 
		for (int k = 1; k <= 3; k++) {
			for (int j = 0; j <= 5000; j++) {
				f[nid][j][k] = (f[nid][j][k] + f[pid][j][k]) % mod; 
				if (j >= a[i]) f[nid][j][k] = (f[nid][j][k] + f[pid][j - a[i]][k - 1]); 
			}
			f[nid][5001][k] = (f[nid][5001][k] + f[pid][5001][k]) % mod; 
			for (int j = 5000 - a[i] + 1; j <= 5001; j++) f[nid][5001][k] = (f[nid][5001][k] + f[pid][j][k - 1]); 
		}
		for (int j = a[i]; j <= 5000; j++) 
			f[nid][j][3] = (f[nid][j][3] + f[pid][j - a[i]][3]) % mod; 
		for (int j = 5000 - a[i] + 1; j <= 5001; j++) f[nid][5001][3] = (f[nid][5001][3] + f[pid][j][3]) % mod; 
		for (int j = 0; j <= 5001; j++) for (int k = 0; k <= 3; k++) f[pid][j][k] = 0; 
	}
	
	printf("%d", ans); 
	
	return 0; 
} 