#include <bits/stdc++.h>
#define int long long 

using namespace std;
const int N = 1e5 + 10;
inline int read () {
	int val = 0, f = 1;
	char ch = getchar ();
	for (; !isdigit (ch); ch = getchar ())
	    if (ch == '-') f = -1;
	for (; isdigit (ch); ch = getchar ())
	    val = (val << 1) + (val << 3) + (ch ^ 48);
	return val * f; 
}
struct comp {
	int p1, p2, val, cha;
};
struct Node {
	comp k[4]; 
} a[N];
struct cmp2 {
	bool operator () (const comp & a, const comp & b) const {
		 return a.cha < b. cha;
	}
};
int T, n, c[4], ans;
priority_queue <comp, vector <comp>, cmp2> q[4];
bool f[N];
bool cmp1 (const comp &a, const comp &b) {
	 return a.val > b. val; 
}
void init () {
	 ans = 0;
     memset (c, 0 , sizeof (c));
	 memset (f, 0, sizeof (f));
}
signed main () {
	
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
    T = read();
    while (T--) {
    	init ();
        n = read();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) 
                a[i].k[j].val = read(), a[i].k[j].p1 = i, a[i].k[j].p2 = j;
		    stable_sort (a[i].k + 1, a[i].k + 1 + 3, cmp1);
		    for (int j = 1; j <= 2; j++) q[j].push ((comp) {a[i].k[j].p1, a[i].k[j].p2, a[i].k[j].val, a[i].k[j].val - a[i].k[j + 1].val});
		    for (int j = 3; j <= 3; j++) q[j].push ((comp) {a[i].k[j].p1, a[i].k[j].p2, a[i].k[j].val, 0});
		}
        for (int i = 1; i <= 3; i++) {
        	while (!q[i].empty()) {
        		 comp l = q[i].top();
        		 //cout << l.cha << ' ';
        		 if (!f[l.p1] && c[l.p2] < (n / 2)) ans += l.val, f[l.p1] = 1, c[l.p2]++;
        		 q[i].pop();
		    }
		}
		cout << ans << endl;
 	}
	return 0;
}




