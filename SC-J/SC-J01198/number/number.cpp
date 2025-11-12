#include<bits/stdc++.h>
//#undef STDIO
const int N = 1e6 + 10;
char s[N];
int a[N], k, n;
int main(){
#ifndef STDIO
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
#endif
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; i++){
		if(isdigit(s[i])){
			a[++k] = s[i] - '0';
		}
	}
	std::sort(a + 1, a + k + 1);
	for(int i = k; i >= 1; i--){
		printf("%d", a[i]);
	}
	fflush(stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}