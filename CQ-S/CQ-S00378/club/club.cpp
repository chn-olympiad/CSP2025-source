/*The code is from @luogu-koukilee*/ 
#include <bits/stdc++.h>

typedef long long i64;
typedef int i32;

const i64 MAXN = 1010100, INF = 992009100720100812;

inline void read (i64& x) {scanf ("%lld", &x);}
inline void print (i64 x) {printf ("%lld", x);}
inline void put (i64 x) {print (x), putchar ('\n');} 

/*
	加油，我将在哪里停留，我问我自己。
	如果直接贪心则是错的，因为同一个机房里面不能分配过多的人
	我们先贪心地考虑，把每个人插到自己所拥有的最大的哪一个地方去
	如果不行，则插入次大的地方去，这样总有一种合理的构造方案可以放得下
	完了，贪心好像假了，不一定对面选次大，我们这边选最大也可以，，
	我们考虑反悔贪心？把放进去的最大值减去次大值选出来，看看放当前是不是更优，， 
	好像又假了，， 
	终于过了，做了一个小时我服了 
*/

struct node {
	i64 id, v;
	
	bool operator < (const node& nex) const {
		return v > nex.v;
	}
} ;

i64 T, n, tot[5];
std::vector <node> s[MAXN];
std::vector <i64> F[4];

int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
		
	read (T);
	
	while (T--) {
		read (n), tot[0] = tot[1] = tot[2] = 0;
		F[0].clear (), F[1].clear (), F[2].clear ();
		
		for (i32 i = 1; i <= n; i++) {
			s[i].clear ();
			for (i32 j = 0; j < 3; j++) {
				i64 v; read (v);
				s[i].push_back ((node) {j, v});
			}
			std::sort (s[i].begin (), s[i].end ());
		}
		
		std::sort (s + 1, s + n + 1) ;
		
		i64 ans = 0;
		
		for (i32 i = 1; i <= n; i++) 
			ans += s[i][0].v, F[s[i][0].id].push_back (s[i][0].v - s[i][1].v); 
		
		for (i32 i = 0; i < 3; i++) {
			if ((i64)F[i].size () > n / 2) {
				std::sort (F[i].begin (), F[i].end ());
				std::reverse (F[i].begin (), F[i].end ());
				while ((i64)F[i].size () > n / 2)
					ans -= F[i].back (), F[i].pop_back ();
			}
		}
		
		put (ans);
	}
	return 0;
}
