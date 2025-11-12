#include <bits/stdc++.h>

using namespace std;

int main (){
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	int n,a[1001];
	scanf ("%d", &n);
	for (int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
	} 
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n - i;j++)
		if (a[j] > a[j + 1]){
			int t = a[j];
			a[j] = a[j + 1];
			a[j + 1] = t;
		}
	}
	int y = 1;
	for (int i = a[1];i <= n;i++)
	y *= i;
	printf ("%d", y);
	return 0;
} 
