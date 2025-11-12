// GZ-S00471 贵阳市第一中学 陈昱竹 
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if(m == 1) printf("%d", n);
	else if(m == n) printf("1");
	return 0;
}
