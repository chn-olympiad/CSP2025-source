#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int cnt[10];
	for(int i = 0;i<10;i++) cnt[i] = 0;
	char c;
	while (scanf("%c", &c), c!='\n'){
		if(c - '0' >= 0 && c - '0' <= 9){
			cnt[c-'0']++;
		}
	}
	for(int i = 9;i>=0;i--){
		while(cnt[i]--) printf("%d", i);
	}
	return 0;
}
