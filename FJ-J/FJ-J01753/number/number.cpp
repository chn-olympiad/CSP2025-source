#include <bits/stdc++.h>
using namespace std;

char c,num[1000001];
int len;

bool cmp(char a, char b) {
	return a > b;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(true) {
		c = getchar();
		if (c < '0' || (c > '9' && c < 'a') || c >'z' || c == EOF) break;
		if (c >= '0' && c <= '9') {
			num[len++] = c;
		}
	}
	sort(num,num+len,cmp);
	printf("%s",num);
	
	return 0;
}
