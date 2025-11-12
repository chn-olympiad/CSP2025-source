#include <bits/stdc++.h>
using namespace std;
const int maxn = 12;
int s[maxn * maxn];
int n, m;
int my;
inline void out(int x, int y, int step){
	if(s[step] == my){
		cout << y << ' ' << x;
		return;
	}
	if(y & 1){
		if(x < n)
			out(x + 1, y, step + 1);
		else
			out(x, y + 1, step + 1);
	}
	else{
		if(x > 1)
			out(x - 1, y, step + 1);
		else
			out(x, y + 1, step + 1);
	}
}
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> s[i];
	my = s[1];
	sort(s + 1, s + n * m + 1, cmp);
	out(1, 1, 1);
	return 0;
}
