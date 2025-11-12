#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[105];
int n, m;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf ("%d%d", &n, &m);
	for (int i = 1;i <= n * m;i++){
		scanf ("%d", &a[i]);
	}
	int target = a[1];
	bool flag = true;
	sort (a + 1, a + 1 + n * m, cmp);
	int x, y, t = m * n;
	x = y = 1;
	for (int i = 1;i <= t;i++){
		if (a[i] == target){
			printf ("%d %d\n", y, x);
			return 0;
		}
		if (flag)++x;
		else --x;
		if (x > n && flag){
			--x;
			++y;
			flag = false;
		}
		 else if (x < 1 && !flag){
			++x;
			++y;
		}
	}
	return 0;
}
