#include <bits/stdc++.h>
using namespace std;
int n, m, x[15][15], y;

struct student{
	int score, id;
}a[225];

bool cmp(student x, student y){
	return x.score < y.score;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);//1
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i].score;
	}//2
	
	int l = a[1].score;
	sort(a + 1, a + n + 1, cmp);
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		if (a[i].score == l){
			y = a[i].id;
			break;
		}
	}//3
	
	int tot = 1;
	for (int j = 1; j <= m; j++){
		if ((j - 1) % 2 == 0){
			for (int i = 1; i <= n; i++){
				x[i][j] = tot++;
			}
		}
		else{
			for (int i = n; i >= 1; i--){
				x[i][j] = tot++;
			}
		}
	}//4
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (y = x[i][j]){
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
