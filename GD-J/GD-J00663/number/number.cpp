#include<bits/stdc++.h>
using namespace std;

template<typename T>
inline void read(T &x) {
	x = 0;
	bool flag = 0;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') flag = !flag;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	
	if(flag)x = -x;
}

template<typename T>
inline void write(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	
	int l = s.size();
	
	for(int num = 9; num >= 0; num--) {
		for(int i = 0; i < l; i++) {
			if(s[i] == (num ^ 48))
				putchar(s[i]);
		}
	}
	
	return 0;
}

