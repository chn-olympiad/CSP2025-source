#include <bits/stdc++.h>
using namespace std;
#define int long long

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	return 0;
}

