#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 50;
long long T, n, ans, cnt[4],f[N][4],maxn = INT_MIN;
long long a[N][4];
void DFS(long long x,long long y){
	if(x == n){
		maxn = max(maxn,f[x][y]);
		return;
	}
	for(int i = 1;i <= 3;i ++){
		if(cnt[i] < n / 2){
			f[x + 1][i] = a[x + 1][i] + f[x][y];
			cnt[i] += 1;
			DFS(x + 1,i);
			f[x + 1][i] = 0;
			cnt[i] -= 1;
		}
	}
}
inline void solve(){
	ans = 0;
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	cnt[1] = cnt[2] = cnt[3] = 0;
	f[1][1] = a[1][1];
	cnt[1] = 1;
	DFS(1,1);
	f[1][1] = 0;
	cnt[1] = 0;
	
	f[1][2] = a[1][2];
	cnt[2] = 1;
	DFS(1,2);
	f[1][2] = 0;
	cnt[2] = 0;
	
	f[1][3] = a[1][3];
	cnt[3] = 1;
	DFS(1,3);
	f[1][3] = 0;
	cnt[3] = 0;
	cout << maxn << '\n';
	maxn = INT_MIN;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> T;
	while(T --){
		solve();
	}
	return 0;
}
