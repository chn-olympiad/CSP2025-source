#include <bits/stdc++.h>
using namespace std;
int n, m;
int score_r;
int seat_r[2];
int score[105];
int seat[11][11];
bool cmp(int x, int y){
	return (x > y);
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> score[i];
	score_r = score[1];
	sort(score + 1, score + n * m + 1, cmp);
	int count = 1;
	for (int i = 1; i <= n; i++){
		if (i % 2 == 0){
			for (int j = m; j >= 1; j--){
				seat[j][i] = score[count];
				if (score[count] == score_r){
					seat_r[0] = j; seat_r[1] = i;
				}
				count ++;
			}
		}
		else {
			for (int j = 1; j <= m; j++){
				seat[j][i] = score[count];
				if (score[count] == score_r){
					seat_r[0] = j; seat_r[1] = i;
				}
				count ++;
			}
		}
	}
	cout << seat_r[1] << " " << seat_r[0];
	return 0;
}
