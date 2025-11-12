#include <bits/stdc++.h>
using namespace std;
int seatslist[12][12], scores[121];
int n, m, a_score;


bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < (m * n); i++) {
		scanf("%d", &scores[i]);
	}
	a_score = scores[0];
	sort(scores, scores+m*n, cmp);
	int k = 0;
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1){
			for (int j = 1; j <= n; j++) {
				seatslist[i][j] = scores[k];
				k++;
			}
		} else {
			for (int j = n; j >= 1; j--) {
				seatslist[i][j] = scores[k];
				k++;
			}
		}	
	}
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (seatslist[i][j] == a_score) printf("%d %d", i, j);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
