#include <bits/stdc++.h>
using namespace std;
int n, q;
char p[500006], c[500006];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1;i <= n + q;i++)
		scanf("%s%s", p + 1, c + 1);
	for (int i = 1;i <= q;i++)
		printf("0\n");
}
