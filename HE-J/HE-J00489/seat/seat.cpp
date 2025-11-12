# include <bits/stdc++.h>
using namespace std;

bool seat[15][15]; /* 座位 */
int score[105];

bool cmp(int a, int b){
	return a>b;
}

int main(){
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int m,n, count=0;
	cin >> n >> m;
	/* 写入分数 */
	for(int i=0;i<m*n;i++) {
		cin >> score [i];
	}
	int a1 = score[0]; /* 记录小R的成绩 */
	sort(score, score+m*n, cmp); /* 按分数由高到低排序 */
	
	/* 查找位置 */
	for (int i=0;i<m;i++){
		if(i%2 == 0){
			for (int j=0; j<n; j++){
				if(score[count] == a1){
					printf("%d %d", i+1, j+1);
					return 0;
				}
				count ++;
			}
		} else {
			for (int j=n-1; j>=0; j--){
				if(score[count] == a1){
					printf("%d %d", i+1, j+1);
					return 0;
				}
				count ++;
			}
		}
	}
	
	return 0;
}
