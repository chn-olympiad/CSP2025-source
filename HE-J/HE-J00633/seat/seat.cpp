#include<bits/stdc++.h>
using namespace std;

int n, m, R, rx=0, ry=0;
int score[110];
int g[15][15];
int dy[3] = {0, 0, 1};
int dx[3] = {1, -1, 0};

bool cmp(int a, int b){
	return a > b;
}

bool search(int x, int y, int down, int rr){
	if (score[down] == rr){
		ry = x;
		rx = y;
		return 1;
	}
	int tx, ty;
	for (int i = 0;i < 3;++i){
		tx = x + dx[i], ty = y + dy[i];
		if (tx > 0 && tx <= n && ty > 0 && ty <= m && !g[tx][ty]){
			g[tx][ty] = score[++down];
			if (search(tx, ty, down, rr))
				return 1;
		}
	}
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	//¶¾Èë 
	cin >> n >> m;
	for (int i = 1;i <= n * m;++i){
		cin >> score[i];
	}
	
	int R = score[1];
	sort(score+1, score+1+n*m, cmp);
	
	g[1][1] = score[1]; 
	search(1, 1, 1, R);
	
//	for (int i = 1;i <= n;++i){
//		for (int j = 1;j <= m;++j){
//			cout << g[i][j] << " ";
//		}puts("");
//	}
//	
	cout << rx << " " << ry;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
