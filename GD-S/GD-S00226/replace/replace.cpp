#include <bits/stdc++.h>
#define LL long long
#define fu(x , y , z) for(int x = y ; x <= z ; x ++)
using namespace std;
const int N = 2e5 + 5 , L = 5e6 + 5;
int n , sl1[N] , sl2[N];
string s1[N] , s2[N];
char t1[N] , t2[N];
int main () {
	freopen ("replace.in" , "r" , stdin);
	freopen ("replace.out" , "w" , stdout);
	int T;
	scanf ("%d%d" , &n , &T);
	fu (i , 1 , n) {
		cin >> s1[i];
		cin >> s2[i];
		sl1[i] = s1[i].length () , sl2[i] = s2[i].length ();
	}
	LL ans;
	int tl1 , a1 , a2 , tl2;
	while (T --) {
		scanf ("%s" , t1 + 1);
		scanf ("%s" , t2 + 1);
		tl1 = strlen (t1) , tl2 = strlen (t2); 
		ans = 0;
		fu (i , 1 , n) {
			if (tl1 + sl2[i] - sl1[i] != tl2) continue;
//			cout << 111;
			fu (j , 1 , tl1 - sl1[i] + 1) {
				int flg = 0;
				for (int k1 = 1 , k2 = j ; k1 <= sl1[i] ; k1 ++ , k2 ++) {
					if (s1[i][k1] != t1[k2]) {
						flg = 1;
						break;
					}
				}
//				cout << 11111;
//				
				if (flg) continue;
				a1 = a2 = 1;
				while (a2 <= tl2) {
					if (a1 == j) {
						fu (k , 1 , sl2[i]) {
							if (s2[i][k] != t2[a2]) {
								flg = 1;
								break;
							}
							a2 ++;
						}
						a1 += sl2[i] - sl1[i];
					}
					else {
						if (t1[a1] != t2[a2]) flg = 1;
						a1 ++ , a2 ++;
					}
					if (flg) break;
				}
				ans += (flg == 0);
			}
		}
		printf ("%lld\n" , ans);
		return 0;
	}
	return 0;
}
