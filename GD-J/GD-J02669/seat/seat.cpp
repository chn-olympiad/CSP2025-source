#include<bits/stdc++.h>
using namespace std;
int n, m;
int st[110];
int idx;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> st[i];
	}
	idx = st[1];
	sort(st + 1, st + 1 + n * m, cmp);
	for(int i = 1; i <= n * m; i++){
		int l = (i - 1) / n + 1, h = i - (l - 1) * n;
		if(st[i] != idx) continue;
		if(l % 2){
			cout << l << ' ' << h;
		}
		else cout << l << ' ' << n - h + 1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

