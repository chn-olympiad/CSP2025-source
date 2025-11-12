#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
char s[N];
int a[N], cnt;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	int l = strlen(s);
	for(int i = 0; i < l; i++){
		char j = s[i];
		if('0' <= j && j <= '9'){
			a[++cnt] = j - '0';
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	for(int i = 1; i <= cnt; i++){
		printf("%d", a[i]);
	}
	return 0;
}