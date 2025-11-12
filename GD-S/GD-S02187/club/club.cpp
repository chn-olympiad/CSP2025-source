#include <bits/stdc++.h>
using namespace std;
const int N = 100005, INF = 0x3f3f3f3f;
struct member{
	int a1, a2, a3;
}a[N];
int T, n;
long long da[205][205][205];
long long dfs(int now, int x, int y, int z){
	if (now == n + 1){
		return 0;
	}
	if (da[x][y][z]){
		return da[x][y][z];
	}
	long long ans = -INF;
	if (x < (n >> 1)){
		ans = max(ans, a[now].a1 + dfs(now + 1, x + 1, y, z));
	}
	if (y < (n >> 1)){
		ans = max(ans, a[now].a2 + dfs(now + 1, x, y + 1, z));
	}
	if (z < (n >> 1)){
		ans = max(ans, a[now].a3 + dfs(now + 1, x, y, z + 1));
	}
	return da[x][y][z] = ans;
}
bool cmp(member a, member b){
	if (a.a1 == b.a1){
		if (a.a2 == b.a2){
			return a.a3 < b.a3;
		}
		return a.a2 < b.a2;
	}
	return a.a1 < b.a1;
} 
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);	
	srand(time(0));
	cin >> T;
	while(T--){
		int flagA = 1, flagB = 1;
		
		cin >> n;
		for (int i = 1; i <= n; ++i){
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			if (a[i].a3 != 0){
				flagA = flagB = 0;
			}
			else if(a[i].a2 != 0){
				flagA = 0;
			}
		}
		/*n = 44;
		for (int i = 1; i <= n; ++i){
			a[i].a1 = rand();
			a[i].a2 = rand();
			a[i].a3 = 0;
		}*/
		if (flagA){
			long long ans = 0;
			sort(a + 1, a + n + 1, cmp);
			for (int i = n; i > (n >> 1); --i){
				ans += a[i].a1;
			}
			cout << ans << "\n";
		}
		else if (flagB){
			long long ans = 0;
			for (int i = 1; i <= n; ++i){
				ans += a[i].a2;
				a[i].a1 -= a[i].a2;
				a[i].a2 = 0;
			}
			sort(a + 1, a + n + 1, cmp);
			for (int i = n; i > (n >> 1); --i){
				ans += a[i].a1;
			}
			cout << ans << "\n";
		}
		else{
			memset(da, 0, sizeof(da));
			cout << dfs(1, 0, 0, 0) << "\n";
		}
	}
	return 0;
} 
