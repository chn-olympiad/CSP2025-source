#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node{ int score; bool me; };
bool cmp(node x, node y) { return x.score > y.score; }

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m; cin >> n >> m;
	vector<node> ranks(n * m);
	for(int i = 0;i < n * m;i++) {
		cin >> ranks[i].score;
		if(!i) ranks[i].me = true;
		else ranks[i].me = false;
	} sort(ranks.begin(), ranks.end(), cmp);
	
	int row = 1, col = 1;
	for(int i = 0;i < n * m;i++) {
		if(ranks[i].me) {
			printf("%d %d", col, row);
			return 0;
		} if(row == n && col % 2) col++;
		else if(row == 1 && !(col % 2)) col++;
		else {
			if(col % 2) row++;
			else row--;
		} 
	}
}
