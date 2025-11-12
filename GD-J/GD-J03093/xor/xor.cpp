#include <bits/stdc++.h>
#define N 100005
#define K 1 << 20

using namespace std;

int n, k, a[N], s, lst, ans;

queue<int> v[K];
inline int rd() {
	int S = 0, F = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') F = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		S = (S << 3) + (S << 1) + (ch ^ 48);
		ch = getchar();
	}
	return S * F;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = rd(); k = rd();
	for(int c, id, i = 1; i <= n; i++) {
		a[i] = rd();
		if(i == 1) {
			s = a[1];
			if(s == k) {
				lst = 1;
				ans ++;
				s = 0;
//				puts("[1, 1]");
			}
			else v[ a[1] ].push(1);
			continue;
		}
		v[ a[i] ].push(i);
		s ^= a[i];
		c = s ^ k;
		
		if(s == k) {
			for(int j = lst + 1; j <= i; j++)
			while(v[ a[j] ].front() <= i && v[ a[j] ].size() ) v[ a[j] ].pop();
			ans ++;
//			printf("[%d, %d]\n", lst + 1, i);
			lst = i;
			s = 0;
		}
		
		else if( v[c].size() && !(i == lst + 1 && c == a[i]) ) {
			id = v[c].front();
			for(int j = lst + 1; j <= i; j++)
			while(v[ a[j] ].front() <= i && v[ a[j] ].size() ) v[ a[j] ].pop();
			ans ++;
//			printf("[%d, %d]\n", id + 1, i);
			lst = i;
			s = 0;
		}
		
	}
	printf("%d", ans);
	return 0;
}
/*
20·Ö 

*/
