#include <bits/stdc++.h>
using namespace std;
const int N = 1000020;
char s_[N];
int a[N], len_s;
bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s_);
	len_s = strlen(s_);
	int j = 0;
	for (int i = 0; i < len_s; i++) {
		if ('0' <= s_[i] && '9' >= s_[i]){
			a[j] = s_[i]-'0';
			j++;
		}
	}
	sort(a, a+j, cmp);
	for (int i = 0; i < j; i++){
		printf("%d", a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
