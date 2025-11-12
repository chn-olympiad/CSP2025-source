#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, cnt;
int score[N];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> score[1];
	for(int i = 2 ; i <= n * m ; i ++){
		cin >> score[i];
		if(score[i] > score[1])
			cnt ++;
	}
	int tot = 0;
	for(int i = 1; i <= m; i ++){
		if(i % 2){
			for(int j = 1 ; j <= n ; j ++){
				tot ++;
				if(tot == cnt + 1){
					cout << i << " " << j << "\n";
					return 0;
				}
			}
		}
		else{
			for(int j = n ; j >= 1 ; j --){
				tot ++;
				if(tot == cnt + 1){
					cout << i << " " << j << "\n";
					return 0;
				}
			}
		}
	}
	return 0;
}
