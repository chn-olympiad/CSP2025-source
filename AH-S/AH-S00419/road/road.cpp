#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int c[N];
int read(){
	int s = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * f;
}
void write(int x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
void build(int u, int v, int w){
	return;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n = read(), m = read(), k = read();
	for(int i = 1; i <= m; i++){
		int u = read(), v = read(), w = read();
		build(u, v, w);
	}
	for(int i = 1; i <= k; i++)
		c[i] = read();
	int t;
	if(t > 0) cout << t << endl;
	else cout << -t << endl;
	return 0;
}
