#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
int a[500001];

int main(){
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &a[i]);
	for (int i = 1;i <= n; i++)
		if (a[i] == k)
			ans++;
	printf ("%d\n", ans);
	return 0;
}
//不怼！我没学过异或！ 
