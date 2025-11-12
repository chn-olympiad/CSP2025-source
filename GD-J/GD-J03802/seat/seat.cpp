#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n, m;
struct node{
	int id, s;
} a[N * N];
bool cmp(node l, node r){
	return l.s > r.s;
}
void dfs(int x, int y, int cnt, int op){
	if(a[cnt].id == 1){
		cout << y << ' ' << x;
		return;
	}
	if(op == 0){
		if(x + 1 > n){
			y++;
			dfs(x, y, cnt + 1, 1);
		}
		else{
			x++;
			dfs(x, y, cnt + 1, 0);
		}
	}
	else{
		if(x - 1 < 1){
			y++;
			dfs(x, y, cnt + 1, 0);
		}
		else{
			x--;
			dfs(x, y, cnt + 1, 1);
		}
	}
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[(i - 1) * n + j].s;
			a[(i - 1) * n + j].id = (i - 1) * n + j;
		}
	}
	sort(a + 1, a + n * m + 1, cmp);
	dfs(1, 1, 1, 0);
	return 0;
}
