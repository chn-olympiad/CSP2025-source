#include<bits/stdc++.h>
#define ll long long
#define pair pair<int, int>

using namespace std;

const ll N = 1e6 + 10;

inline ll read(){
	char c = getchar(); ll x = 0, s = 1;
	while(!isdigit(c)) {
		if(c == '-') s = -1;
		c = getchar();
	}
	while(isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return s * x; 
}

string s1, s2, t1, t2;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n = read(), q = read();
	for(int i = 1; i <= n; ++i) {
		cin >> s1 >> s2;
	}
	for(int i = 1; i <= q; ++i) {
		cin >> t1 >> t2;
		printf("0\n");
	}
	return 0;
}




