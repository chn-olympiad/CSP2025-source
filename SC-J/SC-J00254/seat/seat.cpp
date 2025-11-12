#include<bits/stdc++.h>
using namespace std;
int n, m, s;
int sc[110], seat[20][20];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> sc[i];
	s = sc[1];
	sort(sc + 1, sc + n * m + 1, cmp);
	int idx = 0;
	for(int j = 1; j <= m; j++){
		idx++;
		if(j % 2){
			for(int i = 1; i <= n; i++){
				seat[i][j] = sc[idx];
				idx++;
			}
			idx--;
		}
		else {
			for(int i = n; i >= 1; i--){
				seat[i][j] = sc[idx];
				idx++;
			}
			idx--;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(seat[i][j] == s){
				cout << j << " " << i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}