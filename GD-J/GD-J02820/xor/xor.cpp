#include <bits/stdc++.h>
#define int long long 

using namespace std;
const int N = 5e5 + 10;
inline int read () {
	int val = 0, f = 1;
	char ch = getchar ();
	for (; ch < '0' || ch > '9'; ch = getchar ())
	    if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar ())
	    val = (val << 1) + (val << 3) + (ch ^ 48);
	return val * f; 
}
int n, k, qz[N], a[N];
struct Segment {
	int l, r;
};
queue <Segment> q;

signed main () {
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    qz[1] = a[1];
    for (int i = 2; i <= n; i++)
        qz[i] = qz[i - 1] ^ a[i];
    q.push ((Segment){1, n});
    int ans = 0;
    while (!q.empty ()) {
    	int ll = q.front().l, rr = q.front().r;
    	q.pop();
		if (ll > rr || ll < 1 || ll > n || rr < 1 || rr > n) continue;
		bool flag = 0;
    	for (int i = 1; i <= (rr - ll + 1); i++) {
    		for (int j = ll + i - 1; j <= rr; j++) 
    	  	  if ((qz[j] ^ qz[j - i]) == k) {
    	  	  	 ans++;
    	  	  	 q.push((Segment){ll, j - i});
    	  	  	 q.push((Segment){j + 1, rr});
    	  	  	 flag = 1;
    	  	  	 break;
			  }
			if (flag) break;
		}
    	  
	}
	cout << ans;
	return 0;
} 


