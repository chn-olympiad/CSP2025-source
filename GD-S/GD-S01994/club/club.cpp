#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N][3];
int vis[N];
int fz[N];
bool cmp(int a, int b){
	return a > b;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int t;
	cin >> t;
	while( t -- ) {
		int n, aa[3] = {0, 0, 0};
		long long sum = 0;
		cin >> n;
		for(int i = 1; i <= n; i ++ ) cin >> a[i][0] >> a[i][1] >> a[i][2];
		for(int i = 1; i <= n; i ++ ){
			if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]){
				sum += a[i][0];
				aa[0] ++ ;
				vis[i] = 0;
			}
			else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2]){
				sum += a[i][1];
				aa[1] ++ ;
				vis[i] = 1;
			}
			else{
				sum += a[i][2];
				aa[2] ++ ;
				vis[i] = 2;
			}
		}
		int sx = n / 2;
		bool flag = 0;
		int now, l, r;
		if(aa[0] > sx || aa[1] > sx || aa[2] > sx){
			flag = 1;
			if(aa[0] > sx){
				now = 0;
				l = 1;
				r = 2;
			}
			else if(aa[1] > sx){
				now = 1;
				l = 0;
				r = 2;
			}
			else if(aa[2] > sx){
				now = 2;
				l = 0;
				r = 1;
			}
		}
		if(flag) {
			int j = 0;
			for(int i = 1; i <= n; i ++ ){
				if(vis[i] == now){
					fz[++j] = max(a[i][l] - a[i][now] , a[i][r] - a[i][now]);
				}
			}
			sort(fz + 1, fz + 1 + j, cmp);
			for(int i = 1; i <= aa[now] - sx; i ++ ){
				sum += fz[i];
			}
		}
		cout << sum << "\n";
	}
	return 0;
} 
