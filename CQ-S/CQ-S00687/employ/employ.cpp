#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = 510;

int n, m;
char a[N];
int c[N];
int p[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	scanf("%s", a + 1);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		p[i] = i;
	}
	
	int res = 0;
	do {
		int alr = 0, ok = 0;
		for(int i = 1; i <= n; i++) {
			if(alr >= c[p[i]]) alr++;
			else {
				if(a[i] == '0') alr++;
				else ok++;
			}
		}
		if(ok >= m) res++;
	} while(next_permutation(p + 1, p + 1 + n));
	
	printf("%d\n", res);
	
	return 0;
}
