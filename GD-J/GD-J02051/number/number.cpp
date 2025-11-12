#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int cmp(int a, int b){
	return a>b;
}
int m, n, i, j, k, a[1000005];
char s[1000005];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s+1);
	for(i=1; s[i]; i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1, a+k+1, cmp);
	for(i=1; i<=k; i++){
		printf("%d", a[i]);
	}
	return 0;
} 
