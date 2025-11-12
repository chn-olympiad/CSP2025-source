#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int n, m;
int a[N * N];
int d;
bool vis[N][N];
int way[3][2] = {{1, 0}, {0, 1}, {-1, 0}}, now;
int ans1, ans2;
void init(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			vis[i][j] = 1;
		}
	}
}
bool cmp1(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	init();
	for(int i = 1; i <= n * m; i++){
		scanf("%d", &a[i]);
	}
	d = a[1];
	sort(a + 1, a + (n * m) + 1, cmp1);
	int x = 1, y = 1;
	for(int i = 1; i <= n * m; i++){
		if(a[i] == d){
			ans1 = x;
			ans2 = y;
			break;
		}
		if(!vis[x + way[now][0]][y + way[now][1]]) now = (now + 1) % 3;
		x = x + way[now][0];
		y = y + way[now][1];
	}
	printf("%d %d\n", ans2, ans1);
	return 0;
}
