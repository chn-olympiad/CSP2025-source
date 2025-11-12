#include <bits/stdc++.h>
using namespace std;
char s[1000006];
int a[1000006], sum;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	int l = strlen(s + 1);
	for (int i = 1;i <= l;i++)
		if (s[i] >= '0' && s[i] <= '9')
			a[++sum] = s[i] - '0';
	sort(a + 1, a + sum + 1);
	for (int i = sum;i >= 1;i--)
		printf("%d", a[i]);
}
