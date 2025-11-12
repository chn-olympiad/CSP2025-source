#include<bits/stdc++.h>
using namespace std;

char s[1000010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	sort(s + 1, s + n + 1);
	for(int i = n; i >= 1; i--)
		if(s[i] >= '0' && s[i] <= '9')
			printf("%c", s[i]);
	return 0;
} 
