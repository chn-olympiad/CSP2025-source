#include <bits/stdc++.h>
using namespace std;
const int maxnm = 110;
int n, m;
int furry[maxnm];
void cal(int x) {
	int col = (x + n - 1) / n, row;
	if (col % 2) {
		row = (x - 1) % n + 1;
	}
	else {
		row = n - (x - 1) % n;
	}
	cout << col << ' ' << row << endl;
	return;
}
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	int s;
	cin >> s;
	furry[0] = 114514;
	for (int i = 1; i < n * m; i ++) cin >> furry[i];
	sort(furry + 1, furry + n * m, cmp);
	for (int i = 1; i < n * m; i ++) {
		if (s > furry[i] && s < furry[i - 1]) {
			cal(i);
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

