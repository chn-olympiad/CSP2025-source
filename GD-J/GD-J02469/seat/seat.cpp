#include<bits/stdc++.h>
using namespace std;

int a[20][20];
int score[110];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n*m; i++){
		cin >> score[i];
	}
	int R = score[1];
	sort(score+1, score+1+n*m, greater<int>());
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(R == score[(i-1)*n + j]){
				cout << i << " ";
				if(i % 2 == 0){
					cout << n + 1 - j;
				}
				else cout << j;
			}
		}
	}
	return 0;
}
