#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <iomanip>
#include <set>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

//constexpr i64 N = 1e6 + 10;
constexpr i64 N = 5e5 + 10;
constexpr i64 NM = 1e6 + 10000;
constexpr i64 MOD = 1e9 + 7;
constexpr i64 INF = 1e18;

i64 ans;
int n , k;
int a[N];
int cha[N];
int tot;

struct AFO {
	int x , y;
	bool flag;
} A[N];

int cnt;
std :: set <int> st;


inline bool cmp (AFO a , AFO b) {
	return a.x < b.x;
}

inline void solve1 () {
	int CNT = 0;
	for (int i = 1;i <= n;i ++)
		if (a[i])
			CNT ++;
	std :: cout << CNT + 1 << '\n';
	return ;
}

inline void solve () {
	std :: cin >> n >> k;
	for (int i = 1;i <= n;i ++) std :: cin >> a[i];
	
	for (int i = 1;i <= n;i ++) st.insert (a[i]);
	
	if (st.size () >= 3) {
		cha[1] = a[1];
		
		for (int i = 2;i <= n;i ++)
			cha[i] = cha[i - 1] ^ a[i];
		
		/*
		
		for (int i = 1;i <= n;i ++)
		std :: cout << cha[i] << ' ';
		
		std :: cout << '\n';
		
		*/	
		
		
		
		for (int i = 1;i <= n;i ++)
			if (cha[i] == k) {
				ans ++;
				cnt ++;
//			A[cnt] = {1 , i};
				A[cnt].x = 1 , A[cnt].y = i;
				A[cnt].flag = false;
			}
		
		
		for (int i = 1;i < n;i ++){
			for (int j = i + 1;j <= n;j ++) {
				int dududu = cha[j] ^ cha[i];
				if (dududu == k) {
					ans ++;
					cnt ++;
//				A[cnt] = {i + 1 , j};
					A[cnt].x = i + 1 , A[cnt].y = j;
					A[cnt].flag = false;
				}
			}
		}
		
		std :: sort (A + 1 , A + 1 + cnt , cmp);
		/*
		for (int i = 1;i <= cnt;i ++) {
		std :: cout << A[i].x << ' ' << A[i].y << '\n';
		}
		
		std :: cout << '\n';
		*/
		
		
		for (int i = 1;i <= cnt;i ++) {
			for (int j = i + 1;j <= cnt;j ++) {
				if (A[i].y >= A[j].x) {
					A[j].flag = true;
					if (!A[i].flag && A[j].flag) ans --;
//				std :: cout << A[i].x << ' ' << A[i].y << ' ' << A[j].x << ' ' << A[j].y << '\n';	
				}
			}
		}
		
//	std :: cout << '\n';
		ans = (ans + 2) / 2;
		std :: cout << ans << '\n';
	} else solve1 ();
	
	return ;
}

signed main () {
	freopen ("xor.in" ,"r" , stdin);
	freopen ("xor.out","w",stdout);
	std :: ios :: sync_with_stdio (0);
	std :: cin.tie (0) , std :: cout.tie (0);
	int _;
	_ = 1;
	//std :: cin >> _;
	while (_ --) solve ();
	return (0 - 0);
}

/*

xor

4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3

9:32 fuck,maybe it's time to sleep
zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
baoli ?
But maybe 30~50pts
wwuwuwuwwuwuwuwuiwuwuwuwuwuwuwuwuwuwuwuwuwuw
cutcutcututcutctucutucutucutucuu

*/
