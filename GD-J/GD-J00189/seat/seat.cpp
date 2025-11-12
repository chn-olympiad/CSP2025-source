#include<bits/stdc++.h>
using namespace std;

int n, m, room[105][105];

struct people {
	int score, num;
} a[105];

bool comp(people a, people b) {
	return a.score > b.score;
}

int main() {
	(void)freopen("seat.in", "r", stdin);
	(void)freopen("seat.out", "w", stdout);
	(void)scanf("%d %d", &n, &m);
	int num = n * m;
	for(int i = 1; i <= num; i++) {
		(void)scanf("%d", &a[i].score);
		a[i].num = i;
	}
	sort(a + 1, a + 1 + num, comp);
	int line = 1, row = 1;
	bool type = true;
	for(int i = 1; i <= num && line <= n && row <= m; i++) {
		room[line][row] = a[i].num;
		if(a[i].num == 1) {
			(void)printf("%d %d", row, line);
			break;
		}
		if(type) {
			if(line + 1 <= n) {
				line++;
			} else {
				row++;
				type = false;
			}
		} else {
			if(line - 1 >= 1) {
				line--;
			} else {
				row++;
				type = true;
			}
		}
	}
	return 0;
} 
