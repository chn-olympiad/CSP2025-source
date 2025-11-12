#include<bits/stdc++.h>
using namespace std;

int n, m, xr;
int a[105];

bool cmp(int a, int b){
	return a > b;
}

void dfs(int x, int y, int num){
	if(a[num] == xr){
		cout << y << " " << x << "\n";
		return; 
	}
	if(y % 2 == 1){
		if(x + 1 > n) dfs(x, y + 1, num + 1);
		else dfs(x + 1, y, num + 1);
	}
	else{
		if(x - 1 < 1) dfs(x, y + 1, num + 1);
		else dfs(x - 1, y, num + 1);
	}
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	xr = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	dfs(1, 1, 1);
	return 0;
}
