#include <bits/stdc++.h>
using namespace std;

int a[17], flag = 0;

char c;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while(scanf("%c", &c) && c != '\n'){
		if(c >= '0' && c <= '9'){
			a[c - '0']++;
			flag |= c - '0';
		}
	}
	if(!flag){
		printf("0\n");
		return 0;
	}
	for(int i = 9; i >= 0; i--){
		while(a[i]--){
			printf("%c", i + '0');
		}
	}
	printf("\n");
	return 0;
}
