#include<bits/stdc++.h>
using namespace std;
int seat[110];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n * m; i ++){
		cin >> seat[i];
	}
	int R = seat[0];
	sort(seat, seat + n * m);
	for(int y = 0; y < n * m; y ++){
		int i = n * m - y;
		if(R == seat[y]){
			int l = ((i % n == 0) ? i / n : i / n + 1);
			cout << l << " " << (l % 2 == 0 ? n - (i - (n * (l - 1))) + 1 : ((i - 1) % n + 1));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
