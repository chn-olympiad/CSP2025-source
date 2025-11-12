#include<bits/stdc++.h>
using namespace std;

char s[1000001];
int a[11], m = -1;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	int l = strlen(s + 1);
	for(int i = 1 ; i <= l ; i++){
		if(s[i] >= '0' && s[i] <= '9')
		a[s[i] - '0']++;
		m = max(m, s[i] - '0');
	}
	for(int i = m ; i >= 0 ; i--)
		for(int j = a[i] ; j > 0 ; j--)
			printf("%d", i);
	return 0;
}
