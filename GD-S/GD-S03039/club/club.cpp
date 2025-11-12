#include<bits/stdc++.h>
using namespace std;
int t, n;long long res;
struct node{int data, pos;}x[100005];
struct node1{int data, pos;}y[100005];
struct node2{int data, pos;}z[100005];
bool cmp(node a, node b) {
	return a.data > b.data;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for(scanf("%d", &t); t--; res = 0) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d %d %d", &x[i].data, &y[i].data, &z[i].data);
		sort(x + 1, x + n + 1, cmp);
		for(int i = 1; i <= n / 2; i++)	res += x[i].data;
		printf("%lld\n", res);
	}
	return 0;
}
