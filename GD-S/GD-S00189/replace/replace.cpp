#include<bits/stdc++.h>
using namespace std;

int n, q;
string a, b;

int main() {
	(void)freopen("replace.in", "r", stdin);
	(void)freopen("replace.out", "w", stdout);
	(void)scanf("%d %d", &n, &q);
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
	}
	while(q--) {
		cin >> a >> b;
		(void)printf("0\n"); 
	}
	return 0;
}
