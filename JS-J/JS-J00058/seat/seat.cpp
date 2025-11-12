#include <bits/stdc++.h>
using namespace std;
struct Node {
	short score;
	bool r = false;
};
bool cmp(Node a, Node b) {
	return a.score > b.score;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	vector<Node> score(n * m);
	score[0].r = true;
	for (int i = 0; i < n * m; i++) scanf("%hd", &score[i].score);
	sort(score.begin(), score.end(), cmp);
	for (int i = 0, c = 1, r = 1; i < n * m; i++) {
		if (score[i].r) {
			printf("%d %d\n", c, r);
			return 0;
		}
		if (c & 1) {
			if (r == n) c++;
			else r++;
		}
		else {
			if (r == 1) c++;
			else r--;
		}
	}
    return 0;
}
