/*
csp-s 2025 rp ++
*/
#include<bits/stdc++.h>
#define N 100005
using namespace std;
int t, n, b[3][N], tot[3], ans;
void work(int op, int x){
	if(x != 1 && b[op][x] < b[op][x / 2]){
		swap(b[op][x], b[op][x / 2]);
		work(op, x / 2);
	}
}
void work1(int op, int x){
	if(x * 2 + 1 <= tot[op] && b[op][x * 2 + 1] < b[op][x] && b[op][x * 2 + 1] < b[op][x * 2]){
		swap(b[op][x * 2 + 1], b[op][x]);
		work1(op, x * 2 + 1);
	} 
	else if(x * 2 <= tot[op] && b[op][x * 2] < b[op][x]){
		swap(b[op][x * 2], b[op][x]);
		work1(op, x * 2);
	}
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while(t --){
		cin >> n;
		tot[0] = tot[1] = tot[2] = ans = 0;
		for(int i = 1; i <= n; i ++){
			int x, y, z;
			cin >> x >> y >> z;
			if(x >= y && x >= z){
				ans += x;
				int w = x - max(y, z);
				b[0][++ tot[0]] = w;
				work(0, tot[0]);
			}
			else if(y >= x && y >= z){
				ans += y;
				int w = y - max(x, z);
				b[1][++ tot[1]] = w;
				work(1, tot[1]);
			}
			else if(z >= x && z >= y){
				ans += z;
				int w = z - max(y, x);
				b[2][++ tot[2]] = w;
				work(2, tot[2]);
			}
		}
		while(tot[0] > n / 2){
			ans -= b[0][1];
			swap(b[0][1], b[0][tot[0]]);
			tot[0] --;
			work1(0, 1);
		}
		while(tot[1] > n / 2){
			ans -= b[1][1];
			swap(b[1][1], b[1][tot[1]]);
			tot[1] --;
			work1(1, 1);
		}
		while(tot[2] > n / 2){
			ans -= b[2][1];
			swap(b[2][1], b[2][tot[2]]);
			tot[2] --;
			work1(2, 1);
		}
		cout << ans << '\n';
	}
	return 0;
}
