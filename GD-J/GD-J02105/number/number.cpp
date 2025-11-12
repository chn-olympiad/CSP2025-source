#include<bits/stdc++.h>
#define fo(i, a, b) for(int i = a; i <= b; i ++)

using namespace std;

const int N = 1e6 + 5;

char ch[N];

int num[N], tot;

int cmp(int x, int y) {
	return x > y;
}

signed main() {
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> ch;
	
	int n = strlen(ch);
	
	fo(i, 0, n - 1) {
		if(ch[i] >= '0' && ch[i] <= '9')
		num[++ tot] = ch[i] - '0';
	}
	
	sort(num + 1, num + tot + 1, cmp);
	
	if(num[1] == 0) {//impossible
		cout << 0 << "\n";
		return 0;
	}
	else {
		fo(i, 1, tot)
			cout << num[i];
		cout << "\n";
		return 0;
	}
	
	return 0;
}

