#include<bits/stdc++.h>
using namespace std;

const int N = 15;

struct Student {
	int sc, id;
};

int n, m;
Student s[N * N];
bool cmp(Student x, Student y) {
	return x.sc > y.sc;
}

int main() {
	int i, j;
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	int k = 0;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			scanf("%d", &s[++k].sc);
			s[k].id = k;
		}
	}
	
	sort(s + 1, s + 1 + k, cmp);
	
	k = 0;
	for (i = 1; i <= m; ++i) {
		if (i % 2 == 1) {
			for (j = 1; j <= n; ++j) {
				++k;
				
				if (s[k].id == 1) {
					printf("%d %d", i, j);
					return 0;
				}
			}
		}
		else {
			for (j = n; j > 0; --j) {
				++k;
				
				if (s[k].id == 1) {
					printf("%d %d", i, j);
					return 0;
				}
			}
		}
	}
	
	return 0;
}

