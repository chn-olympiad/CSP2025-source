#include <bits/stdc++.h>
using namespace std;

const int maxs = 1e6 + 5;

int tot;
int a[maxs];
string s;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out","w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; ++i){
		if ('0' <= s[i] && s[i] <='9'){
			a[++tot] = s[i] - '0';
		}
	}
	sort(a + 1, a + tot + 1, cmp);
	for (int i = 1; i <= tot; ++i){
		cout << a[i];
	}
	return 0;
}
