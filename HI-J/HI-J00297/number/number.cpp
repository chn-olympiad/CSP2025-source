#include <iostream>
#include <cstdio>
using namespace std;

int cnt,num[10];
char s[1010000];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%s",s+1);
	while (s[++cnt] != '\0') {
		if (s[cnt] >= '0' && s[cnt] <= '9') {
			num[s[cnt]-'0']++;
		}
	}
	for (int i = 9;i >= 0;i--) {
		for (int j = 1;j <= num[i];j++) printf("%d",i);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
