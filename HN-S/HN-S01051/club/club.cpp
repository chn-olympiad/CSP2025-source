#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int t, n, cnt, ans;

int a[maxn][5], f[maxn];

void solve_1(){
	a[2][1] += max(a[1][2], a[1][3]);
	a[2][2] += max(a[1][1], a[1][3]);
	a[2][3] += max(a[1][1], a[1][2]);
	cout << max(a[2][1], max(a[2][2], a[2][3])) << "\n";
}

void solve_a(){
	for(int i = 1; i <= n; i ++){
		f[i] = a[i][1];
	} 
	sort(f + 1, f + 1 + n);
	for(int i = n; i > n / 2; i --){
		ans += f[i];
	} 
	cout << ans << "\n";
}

int x[maxn], y[maxn], z[maxn];

void solve(){
	for(int i = 1; i <= n; i ++){
		x[i] = a[i][1], y[i] = a[i][2], z[i] = a[i][3];
	}
	sort(x + 1, x + 1 + n);
	sort(y + 1, y + 1 + n);
	sort(z + 1, z + 1 + n);
	int cnt_x = 0, cnt_y = 0, cnt_z = 0;
	
	for(int i = n; i > n / 2; i --){
		cnt_x += x[i]; 
		cnt_y += y[i]; 
		cnt_z += z[i]; 
	}
	
	if(cnt_x >= cnt_y && cnt_x >= cnt_z){
		cout << "x";
		ans += cnt_x;
		int p = x[n / 2];
		for(int i = 1; i <= n; i ++){
			if(a[i][1] > p){
				a[i][2] = a[i][3] = 0;
			} 
		} 
		for(int i = 1; i <= n; i ++){
			cnt += max(a[i][2], a[i][3]);
		}
		cout << ans + cnt << "\n";
	}
	if(cnt_y >= cnt_x && cnt_y >= cnt_z){
		cout << "y";
		ans += cnt_y;
		int p = y[n / 2];
		for(int i = 1; i <= n; i ++){
			if(a[i][2] > p){
				a[i][1] = a[i][3] = 0;
			} 
		} 
		for(int i = 1; i <= n; i ++){
			cnt += max(a[i][1], a[i][3]);
		}
		cout << ans + cnt << "\n";
	}
	if(cnt_z >= cnt_x && cnt_z >= cnt_y){
		cout << "z";
		ans += cnt_z;
		int p = z[n / 2];
		for(int i = 1; i <= n; i ++){
			if(a[i][3] > p){
				a[i][1] = a[i][3] = 0;
			} 
		} 
		for(int i = 1; i <= n; i ++){
			cnt += max(a[i][1], a[i][2]);
		}
		cout << ans + cnt << "\n";
	}
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cnt = ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i ++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2] == 0 && a[i][3] == 0){
				cnt ++;
			}
		}
		if(n == 2){
			solve_1();
		}else if(cnt == n){
			solve_a();
		}else{
			solve();
		}
	}
	
	return 0;
}
