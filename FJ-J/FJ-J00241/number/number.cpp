#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
char a;
int h, s[1000006];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin >> a){
		if(a >= '0' && a <= '9')s[h++] = a - '0';
	}
	sort(s, s + h, cmp);
	for(int i = 0; i < h; i++){
		printf("%d", s[i]);
	}
	return 0;
}

