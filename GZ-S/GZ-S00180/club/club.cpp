// GZ-S00180 黔南布依族苗族自治州都匀第一中学 张铮瀚
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n;
#define maxn 1003
int a[maxn][3];
int maxv[maxn][4]; 
int ans = 0;

int maxx(int a,int b,int c) {
	int temp;
	if(a > b) temp = a;
	else temp = b;
	
	if(c>temp) return c;
	else return temp;
}

int h(int cur) {
	int best = 0;
	return maxv[n][0] - maxv[cur - 1][0];
}

void dfs(int i, int v, int a1,int a2,int a3) {
	if(i > n + 1 || v + h(i) < ans) 
		return;
			
	if(v > ans) {
		ans = v;
	}
	
	if(a1 < n/2) { 
		dfs(i + 1, v + a[i][0], a1 + 1, a2, a3);
	}else if(v + maxv[n][1] - maxv[i - 1][1] < ans) 
		return;
	
	if(a2 < n/2) {
		dfs(i + 1, v + a[i][1], a1, a2 + 1, a3);
	}else if(v + maxv[n][2] - maxv[i - 1][2] < ans)
		return;
		 
	if(a3 < n/2) {
		dfs(i + 1, v + a[i][2], a1, a2, a3 + 1);
	}else if(v + maxv[n][3] - maxv[i - 1][3] < ans) 
		return;
}



void solve() {
	cin >> n;
	memset(a, 0 ,sizeof(a));
	ans = -1;
	
	for(int i = 1; i<=n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		maxv[i][0] = maxv[i - 1][0] + maxx(a[i][1],a[i][2],a[i][0]);
		 
		maxv[i][1] = maxv[i - 1][1] = max(a[i][3],a[i][2]);
		maxv[i][2] = maxv[i - 1][2] = max(a[i][1],a[i][3]);
		maxv[i][3] = maxv[i - 1][3] = max(a[i][1],a[i][2]);
	}
	dfs(1,0,0,0,0);
	cout << ans << endl;
}

int main() {
	freopen("club.in","r", stdin);
	freopen("club.out","w",stdout);
	 
	int t;
	cin >> t;
	for(int _i = 0; _i < t; ++_i) {
		solve();
	}
	return 0;
}
