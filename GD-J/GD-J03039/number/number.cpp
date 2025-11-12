#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string furry;
	cin >> furry;
	int cnt = 0;
	for (int i = 0; i < furry.size(); i ++) {
		if (furry[i] >= '0' && furry[i] <= '9') {
			a[++ cnt] = furry[i] - '0';
		}
	}
	sort(a + 1, a + 1 + cnt);
	for (int i = cnt; i >= 1; i --) {
		cout << a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
	PhigrosÌ©ºÀÍæÁ¦£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
	MCÌ©ºÀÍæÁ¦ £¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
	FurryÌ©À«°«Á¦£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
*/ 
