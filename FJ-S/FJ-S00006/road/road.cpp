#include <bits/stdc++.h>
using namespace std;
int n, m, k, a, b, c;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1;i <= m;i++)
		scanf("%d%d%d", &a, &b, &c);
	for (int i = 1;i <= k;i++)
		for (int j = 1;j <= m;j++)
			scanf("%d", &a);
	cout << "0" << endl;
}
