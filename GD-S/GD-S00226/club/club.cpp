#include <bits/stdc++.h>
#define fu(x , y , z) for(int x = y ; x <= z ; x ++)
#define LL long long
using namespace std;
const int N = 1e5 + 5;
int n , s[5] , mx[N] , mn[N] , md[N];
LL a[N][5] , c[N] , ans;
struct Q {
	int id;
	LL v;
	bool operator < (const Q &t) const {
		return v < t.v;
	}
	bool operator > (const Q &t) const {
		return v > t.v;
	}
} ;
priority_queue<Q , vector<Q> , greater<Q>> q[5];
int main () {
	freopen ("club.in" , "r" , stdin);
	freopen ("club.out" , "w" , stdout);
    int T , n1;
    Q tp;
    scanf ("%d" , &T);
    while (T --) {
        scanf ("%d" , &n);
        n1 = n / 2;
		fu (i , 1 , n) {
            fu (j , 1 , 3) {
                scanf ("%lld" , &a[i][j]);
            }
            if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
            	mx[i] = 1 , md[i] = 2 , mn[i] = 3;
            	if (a[i][2] < a[i][3]) swap (md[i] , mn[i]); 
			}
			else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
            	mx[i] = 2 , md[i] = 1 , mn[i] = 3;
            	if (a[i][1] < a[i][3]) swap (md[i] , mn[i]); 
			}
			else {
            	mx[i] = 3 , md[i] = 1 , mn[i] = 2;
            	if (a[i][1] < a[i][2]) swap (md[i] , mn[i]); 
			}
			c[i] = a[i][mx[i]] - a[i][md[i]];
        }
        fu (i , 1 , 3) {
        	while (!q[i].empty()) q[i].pop();
		}
        s[1] = s[2] = s[3] = 0;
        ans = 0;
        fu (i , 1 , n) {
        	ans += a[i][mx[i]];
			s[mx[i]] ++;
			if (s[mx[i]] <= n1) {
                q[mx[i]].push((Q){i , c[i]});
                continue;
            }
			s[mx[i]] = n1;
			q[mx[i]].push((Q){i , c[i]});
			tp = q[mx[i]].top();
        	q[mx[i]].pop();
        	ans -= tp.v;
            q[md[i]].push((Q){tp.id , c[tp.id]});
		}
		printf ("%lld\n" , ans);
    }
    return 0;
}
