#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 1000005
using namespace std;

int i, c;
char s[N], f[N];
bool cmp(char x, char y){
	return x > y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	for(i=0; s[i]; i++){
		if(isdigit(s[i]))	f[c++] = s[i];
	}
	sort(f, f+c, cmp);
	puts(f);
	fclose(stdin), fclose(stdout);
	return 0;
}
