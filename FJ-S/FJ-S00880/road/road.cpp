#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>
#define endl '\n'
#define freeorphan freopen
const int MAXN = 10015;
const int MAXM = 4000015;
const int inf = 0x7f7f7f7f;
using namespace std;
using ll = long long;
ll n, m, k, q=0, fa[MAXN], cj[15];
bool mark[MAXN], vis[MAXN];

struct edge{
	ll u, v, w;
}g[MAXM];

bool cmp(edge a, edge b){
	return a.w < b.w;
}

inline ll mst(){
	// yes now its right
	for(ll i=1; i<=n+k; ++i)
		fa[i] = i;
	const ll len = q;
	sort(g+1, g+len+1, cmp);
	ll ans = 0, cnt = 0;
	for(ll i=1; i<=len; ++i){
		ll eu = g[i].u, ev = g[i].v;
		if(fa[eu] != eu) 
			continue;
		fa[eu] = ev;
		ans += g[i].w;
		if(eu > n && !mark[i]){
			// with A, ignore that cj[i] may greater that 0;
			// so i even dont need mark[]
			// but just in case, i left this if here
		 	ans += cj[i];
		 	mark[eu] = true;
		}
		++cnt;
		if(cnt == n-1) 
			break;
	}
	return (cnt == n-1) ? ans : inf;
}

int main(void){
	memset(mark, false, sizeof mark);
	memset(vis, false, sizeof vis);
	memset(g, -1, sizeof g);
	freeorphan("road.in", "r", stdin);
    freeorphan("road.out", "w", stdout); 
	cin >> n >> m >> k;
	for(ll i=1, u, v, w; i<=m; ++i){
		cin >> u >> v >> w;
		g[++q] = {u, v, w};
	}
	for(ll i=1; i<=m; ++i){
		cin >> cj[n+i];
		for(ll j=1, w; j<=n; ++j){
			cin >> w;
			g[++q] = {j, n+i, w};
		}
	}
	cout << mst() << endl;
	return 0;
	for(;2==1;){
/*
too long i need to hide this in dev-cpp plzplzplz

11/01 15:03 omg thank you ccf it's graph
11/01 15:13 'obviously' its mst but i can so i cant get 20pts
11/01 15:23 wait is it layered mst
11/01 15:25 i have a good idea for correct answer
            i just need to add a new array
            to store "the country turns to the city or not"
11/01 15:27 ok now i am basically re-inventing kruskal
11/01 15:31 (MY POOR HEAD THINK plzplzplz!!!!!!)
11/01 15:54 OK done let me try
11/01 16:01 throw warning: road2.in -> 16 != 13 <- road2.ans
11/01 16:21 sleepy
11/01 16:35 not all mst
11/01 16:59 1.5h left for real
11/01 17:05 finish kruskal first
11/01 17:17 i have tested kruskal for a long time and
            IT IS CONFIRMED THAT IT IS WRONG
            CSP-J2 is better than CSP-S2 (hot take)
11/01 17:32 throw error: road2.in -> 6 != 13 <- road2.ans
            and im sleepy
11/01 17:37 actually i spent 2h in re-inventing kruskal
            BUT NOW IT IS CORRECT!!!! 1h left
11/01 17:40 finally i can get sub 1~4 (16pts)
            noticed that A -> +32pts
11/01 17:43 sub 13, 14 detected TLE
11/01 17:51 give up, __>+o_= <- sleep
11/01 17:57 replace.cpp is TOO hard so i come back
            realized i didnt bring water and food
            im starving
11/01 18:08 get some pts from T3,4
11/01 18:15 waiting for end
            im not lucid now
11/01 18:21 last 9mins->bye bye OI

CCF orz orz orz sto sto sto NOI
yxx ORZ ORZ ORZ STO STO STO hqh
subscribe Astralyn_S (^-^) (FJ-S00880 / FJ-J00987)
*/
	}
}

// exp 0~48pts
