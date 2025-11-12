#include<bits/stdc++.h>
using namespace std;
int n, m, ls[105], rscore, rindex;
int fill[15][15];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m; ++ i){
		cin >> ls [ i ];
		if (i == 1) rscore = ls [ i ];
	}
	sort(ls + 1, ls + n * m + 1, greater<int>());
	for (int i = 1;i <= n * m; ++ i) if (ls [ i ] == rscore) rindex = i;
	int tmpa = (rindex - 1) / n + 1;
	int tmpb = (rindex - 1) % m + 1;
	cout << tmpa << " ";
	if (tmpa % 2){
		cout << tmpb;
	}else cout << m - tmpb + 1;
	return 0;
}
