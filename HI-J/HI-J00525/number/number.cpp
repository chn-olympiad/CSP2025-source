#include <bits/stdc++.h>

using namespace std;

int c[1005];

int main (){
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	char s[1005];
	int a[1005];
	int l,t = 1;
	scanf ("%s", s + 1);
	l = strlen (s + 1);
	for (int i = 1;i <= l;i++){
		a[i] = s[i] - '0';
		if (a[i] < 10){
			c[t] = a[i];
			t++;
		}
	}
	for (int i = 1;i <= t;i++)
	for (int j = 1;j <= t - i;j++)
	if (c[j] < c[j + 1]){
		int t = c[j];
		c[j] = c[j + 1];
		c[j + 1] = t;
	}
	for (int i = 1;i <= t - 1;i++)
	printf ("%d", c[i]);
	return 0;
}
