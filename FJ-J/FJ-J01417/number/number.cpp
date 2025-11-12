//CSP 2025 RP++
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
char c;
int top, num[N];
bool cmp(int x, int y){ return x > y; }
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while(scanf("%c", &c) == 1){
		if(isdigit(c)) num[++top] = c - 48;
		//putchar(c);
	}
	sort(num + 1, num + 1 + top, cmp);
	for(int i = 1; i <= top; i++) putchar(48 + num[i]);
	return 0;
}
