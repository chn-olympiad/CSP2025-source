#include <bits/stdc++.h>

using namespace std;

const int MAXN = 15;
int N,M;
int Mapn[MAXN][MAXN];
int score[105];

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> N >> M;
	const int people = N * M;
	for(int i = 1;i <= people;i ++)
		cin >> score[i];
	int ScoreR = score[1];
	for(int i = 1;i <= people;i ++)
		for(int j = 1;j <= people;j ++)
			if(score[i] > score[j])
				swap(score[i],score[j]);

	int cnt = 0;
	for(int i = 1;i <= M;i ++) {
			if(i % 2 == 1)
				for(int j = 1;j <= N;j ++) {
					cnt ++;
					Mapn[j][i] = score[cnt];
//
				}
					
			else
				for(int j = N;j >= 1;j --) {
					cnt ++;
					Mapn[j][i] = score[cnt];
//
				}
	}
	for(int i = 1;i <= M;i ++)
		for(int j = 1;j <= N;j ++)
			if(Mapn[i][j] == ScoreR) {
				cout << j << " " << i;
				return 0;
			}
	return 0;
}
