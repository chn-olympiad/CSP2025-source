#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	
	vector<int> grades;
	int xmgrade;
	
	for(int i = 0; i < n * m; i++) {	
		int tmp;
		cin >> tmp;
		grades.push_back(tmp);
	}
	
	xmgrade = grades[0];
	sort(grades.begin(), grades.end(), cmp);

	int xmidx;
	for(int i = 0; i < n * m; i++) {
		if(grades[i] == xmgrade) {
			xmidx = i;
			break;
		}
	}
	xmidx = xmidx;
	int lie = (xmidx / n) + 1;
	int hang;
	if(lie % 2 == 0) hang = n - (xmidx % n);
	else hang = (xmidx % n) + 1;
	
	cout << lie << " " << hang << "\n";
	return 0;
}
