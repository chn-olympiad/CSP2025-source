#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
char s[N];
int a[N];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	int n = strlen(s + 1), cnt = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++cnt] = s[i] - '0';
		}
	}
	sort(a + 1, a + cnt + 1);
	for(int i = cnt; i >= 1; i--){
		printf("%d", a[i]);	
	}
	putchar(10);
	fclose(stdin);
	fclose(stdout);
	return 0;
}