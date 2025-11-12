#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr i64 N = 1e5 + 10;
constexpr i64 INF = 1e18;
constexpr i64 MOD = 1e9 + 7;

i64 ans;
int _;
int n;
int nn;
int tot[N];

struct club {
	int x , y , z , id;
} a[N] , b[N] , c[N] , yuan[N];

int cnt[3];

inline bool cmp1 (club a , club b);
inline bool cmp2 (club a , club b);
inline bool cmp3 (club a , club b);

inline void test ();

inline void solve () {
	ans = 0;
	std :: memset (cnt , 0 , sizeof (cnt));
	std :: memset (tot , 0 , sizeof (tot));
	std :: cin >> n;
	nn = n / 2;
	for (int i = 1;i <= n;i ++) {
		std :: cin >> a[i].x >> a[i].y >> a[i].z;
		a[i].id = i;

	}
	for (int i = 1;i <= n;i ++) {
		b[i] = {a[i].x , a[i].y , a[i].z , a[i].id};
		c[i] = {a[i].x , a[i].y , a[i].z , a[i].id};
		yuan[i] = {a[i].x , a[i].y , a[i].z , a[i].id};
	}

	std :: sort (a + 1 , a + 1 + n , cmp1);
	std :: sort (b + 1 , b + 1 + n , cmp2);
	std :: sort (c + 1 , c + 1 + n , cmp3);
	
//	std :: cout << '\n';
	
//	test ();	
	
	int pos1 = 1 , pos2 = 1 , pos3 = 1;

	for (int i = 1;i <= n;i ++) {
		bool flag = false;
		if(a[pos1].x >= std :: max <int> (b[pos2].y , c[pos3].z) && cnt[1] < nn && flag == false) {
			if (tot[a[pos1].x] < n - 1 && tot[a[pos1].x] > nn) continue;
			flag = true;
			ans += a[pos1].x;
			cnt[1] ++;
			tot[a[pos1].id] ++;
			pos1 ++;
		} if(b[pos2].y >= std :: max <int> (a[pos1].x , c[pos3].z) && cnt[2] < nn && flag == false) {
			if (tot[b[pos2].y] < n - 1 && tot[b[pos2].y] > nn) continue;
			flag = true;
			ans += b[pos2].y;
			cnt[2] ++;
			tot[b[pos2].id] ++;
			pos2 ++;
		} if(c[pos3].z >= std :: max <int> (a[pos1].x , b[pos2].y) && cnt[3] < nn && flag == false) {
			if (tot[c[pos3].z] < n - 1 && tot[c[pos3].z] > nn) continue;
			flag = true;
			ans += c[pos3].z;
			cnt[3] ++;
			tot[c[pos3].id] ++;
			pos3 ++;
		}
	}	
	
	/*
	
	std :: cout << pos1 << ' ' << pos2 << ' ' << pos3 << '\n';
	
	for (int i = 1;i <= n;i ++) std :: cout << tot[i] << ' ';
	std :: cout << '\n';
	
	
	*/
	
//	/*
	
	for (int i = 1;i <= n;i ++) {
		if (tot[i] == 0) {
			int mxid;
			for (int j = 1;j <= n;j ++) {
				if (yuan[j].id == i) {
					mxid = j;
					break;
				}
			}
			if (yuan[mxid].x >= std :: max <int> (yuan[mxid].y , yuan[mxid].z) && (a[pos1 - 1].x <= yuan[mxid].x || (yuan[mxid].y == 0 && yuan[mxid].z == 0))) {
//				std :: cout << "asdf" << '\n';
				ans -= a[pos1 - 1].x;
				ans += yuan[mxid].x;
			} else if (yuan[mxid].y >= std :: max <int> (yuan[mxid].x , yuan[mxid].z) && (b[pos2 - 1].y <= yuan[mxid].y && (yuan[mxid].x == 0 && yuan[mxid].z == 0))) {
//				std :: cout << "asdfasdfasdf" << '\n';
				ans -= b[pos2 - 1].y;
				ans += yuan[mxid].y;
			} else if (yuan[mxid].z >= std :: max <int> (yuan[mxid].y , yuan[mxid].x) && (c[pos3 - 1].z <= yuan[mxid].z || (yuan[mxid].x == 0 && yuan[mxid].y == 0))) {
//				std :: cout << "asdfasdfasdfsadfsadf" << '\n';
				ans -= c[pos3 - 1].z;
				ans += yuan[mxid].z;
			}
		}
	}
	
//	*/.
	
	/*
	for (int i = 1;i <= n;i ++) {
		if (tot[i] == 0) {
			int mxid;
			for (int j = 1;j <= n;j ++) {
				if (yuan[j].id == i) {
					mxid = j;
					break;
				}
			}
		}
	}
	
	*/
	
		
	std :: cout << ans << '\n';
	return ;
}

signed main () {
	freopen ("club.in" , "r" , stdin);
	freopen ("club.out" , "w" , stdout);
	std :: ios :: sync_with_stdio (0);
	std :: cin.tie (0) , std :: cout.tie (0);
	//_ = 1;
	std :: cin >> _;
	while (_ --) solve ();	
	return (0 - 0);
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13

*/

inline void test () {
	for (int i = 1;i <= nn;i ++)
		std :: cout << a[i].x << ' ' << a[i].y << ' ' << a[i].z << ' ' << a[i].id << '\n';
	
	std :: cout << '\n';
	
	for (int i = 1;i <= nn;i ++)
		std :: cout << b[i].x << ' ' << b[i].y << ' ' << b[i].z << ' ' << b[i].id << '\n';
	
	std :: cout << '\n';	
	
	for (int i = 1;i <= nn;i ++)
		std :: cout << c[i].x << ' ' << c[i].y << ' ' << c[i].z << ' ' << c[i].id << '\n';
	
	std :: cout << '\n';
	return ;
}

inline bool cmp1 (club a , club b) {
	return a.x > b.x;
}

inline bool cmp2 (club a , club b) {
	return a.y > b.y;
}

inline bool cmp3 (club a , club b) {
	return a.z > b.z;
}
