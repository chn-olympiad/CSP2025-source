#include<bits/stdc++.h>
using namespace std;

int n, m, idx, rscore, score[110], seat[20][20];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 0; i < n * m; i++) cin >> score[i];
	rscore = score[0];
	
	sort(score, score + n * m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) seat[i][j] = score[i * n + j];
	for(int i = 1; i < n; i += 2)
		for(int j = 0; j * 2 <= m; j++){
			int tmp = seat[i][j];
			seat[i][j] = seat[i][m - j - 1];
			seat[i][m - j - 1] = tmp;
		}
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(seat[i][j] == rscore){
				cout << j + 1 << ' ' << i + 1;
				break;
			}
	
	return 0;
} 
