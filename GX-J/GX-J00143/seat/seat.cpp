#include <iostream>
#include <algorithm>

using namespace std;

bool rev(int a, int b) {return a > b;}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int grade[110], user;
	int n, m;
	
	scanf("%d%d", &n, &m);
	
	for(int i = 0; i < n * m; i++) scanf("%d", &grade[i]);
	
	user = grade[0];
	
	sort(grade, grade + n * m, rev);
	
	for(int i = 0, cnt = 0; i < m; i++) {
		for(int j = 0, f = 1; j < n; j += f) {
			if(grade[cnt++] == user) {
				printf("%d %d", i + 1, j + 1);
				return 0;
			}
		}
	}
	
	return 0;
}
