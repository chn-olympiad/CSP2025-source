#include<bits/stdc++.h>
#define fr(i, x, y) for (int i = (x); i <= (y); i ++)
using namespace std;
const int N = 1e6 + 6;
char s[N], num[N];
int cnt, len;
bool cmp(char x, char y){ return x > y; }
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	len = strlen(s + 1);
	fr(i, 1, len) if (s[i] >= '0' && s[i] <= '9') num[++ cnt] = s[i];
	sort(num + 1, num + cnt + 1, cmp);
	printf("%s", num + 1);
	return 0;
}