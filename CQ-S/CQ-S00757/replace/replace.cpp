#include <bits/stdc++.h>

using namespace std;

int n, m, a[200100], ans;
char c[200100][2][1000], s[2][1000];

int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%s", c[i][0] + 1);
		scanf ("%s", c[i][1] + 1);
		a[i] = strlen (c[i][0] + 1);
	}
	for (int i = 1; i <= m; i++) {
		scanf ("%s", s[0] + 1);
		scanf ("%s", s[1] + 1);
		int x = strlen (s[0] + 1);
		int y = strlen (s[1] + 1);
		ans = 0;
        for (int j = 1; j <= x; j++) {
        	//printf ("a %d\n", j);
        	if (s[0][j - 1] != s[1][j - 1] || x != y) {
            	break;
        	}
            for (int k = 1; k <= n; k++) {
                if (x - j + 1 < a[k]) {
                    continue;
                }
                for (int w = 1; w <= a[k]; w++) {
                	//printf ("%d %d %d %d\n", j, w, k, a[k]);
                    if (s[0][j + w - 1] != c[k][0][w]) {
                        break;
                    }
                    //printf ("b\n");
                    if (s[1][j + w - 1] != c[k][1][w]) {
                        break;
                    }
                    //printf ("c\n");
                    if (w == a[k]) {
                    	//printf ("d\n");
                    	if (j + w == y + 1) {
                    		ans++;
                    		//printf ("d %d\n", ans);
						}
                    	for (int l = j + w; l <= y; l++) {
                    		//printf ("f %d\n", l);
                    		if (s[0][l] != s[1][l]) {
                    			break;
							}
							//printf ("g %d %d\n", l, y);
							if (l == y) {
								ans++;
								// printf ("h %d\n", ans);
							}
						}
                    }
                }
            }
        }
  	  printf ("%d\n", ans);
	}
}
