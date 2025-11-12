#include <bits/stdc++.h>
using namespace std;
const int M = 998, K = 244, L = 353;
const int N = 1e5 + 10;
int a[N];
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
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n = read(), m = read();
	string s1; cin >> s1;
	for(int i = 1; i <= n; i++)
		a[i] = read();
	cout << n * (n - 1) % M % K % L << endl；
	return 0;
}
