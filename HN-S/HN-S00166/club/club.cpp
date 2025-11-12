#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;

int n;
int x, y, z;

struct node{
	int num, t;
}a[N + 5];
int cnt[5];

int t;

inline bool cmp(node x, node y){
	if(x.num == t && y.num == t) return x.t > y.t;
	if(x.num == t) return 1;
	if(y.num == t) return 0;
	return 0;
}

int ans;

inline void clear(){
	ans = 0;
	cnt[1] = cnt[2] = cnt[3] = t = 0;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T --){
	
	cin >> n;
	for(int i = 1; i <= n; ++ i){
		cin >> x >> y >> z;
		if(x >= y && x >= z){
			if(y >= z){
				a[i].t = y - x;
				a[i].num = 1;
				++ cnt[1];
				ans += x;
			}
			else{
				a[i].t = z - x;
				a[i].num = 1;
				++ cnt[1];
				ans += x;
			}
		}
		else if(y > x && y >= z){
			if(x >= z){
				a[i].t = x - y;
				a[i].num = 2;
				++ cnt[2];
				ans += y;
			}
			else{
				a[i].t = z - y;
				a[i].num = 2;
				++ cnt[2];
				ans += y;
			}
		}
		else{
			if(y >= x){
				a[i].t = y - z;
				a[i].num = 3;
				++ cnt[3];
				ans += z;
			}
			else{
				a[i].t = x - z;
				a[i].num = 3;
				++ cnt[3];
				ans += z;
			}
		}
	}

	for(int i = 1; i <= 3; ++ i){
		// cout << cnt[i] << '\n';
		if((cnt[i] << 1) > n){
			t = i;
			break;
		}
	}
	// cout << ": " << ans << '\n';

	if(t){
		sort(a + 1, a + n + 1, cmp);
		int i = 1;
		while((cnt[t] << 1) > n){
			ans += a[i].t;
			++ i;
			-- cnt[t];
		}
	}

	cout << ans << '\n';
	clear();

	}

	return 0;
}