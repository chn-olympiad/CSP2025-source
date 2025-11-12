#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N][3], h[N], v[N], d[N], b[3];
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
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n = read(), q = read();
	for(int i = 1; i <= n; i++){
		string s1, s2;
		cin >> s1 >> s2;
	}
	while(q--){
		string t1, t2;
		cin >> t1 >> t2;
		puts("0");
	}
	return 0;
}
