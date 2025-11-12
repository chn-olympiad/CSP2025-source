#include<bits/stdc++.h>
using namespace std;
int t, sum, n, x, y, z;
struct node{
	int w1, w2, w3;
}a[100005];
bool cmp(node L, node R){
	if (abs(L.w1 - R.w2) != abs(R.w1 - L.w2)) return abs(L.w1 - R.w2) > abs(R.w1 - L.w2);
	if (abs(L.w1 - R.w3) != abs(R.w1 - L.w3)) return abs(L.w1 - R.w3) > abs(R.w1 - L.w3);
	if (abs(L.w2 - R.w3) != abs(R.w2 - L.w3)) return abs(L.w2 - R.w3) > abs(R.w2 - L.w3);
	if (L.w1 != R.w1) return L.w1 > R.w1;
	if (L.w2 != R.w2) return L.w2 > R.w2;
	return L.w3 > R.w3;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		x = 0, y = 0, z = 0, sum = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%d", &a[i].w1);
			scanf("%d", &a[i].w2);
			scanf("%d", &a[i].w3);
		}
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; i++){
			if (a[i].w1 > a[i].w2 && x < n / 2){
				if (a[i].w1 < a[i].w3 && z < n / 2) z++, sum += a[i].w3;
				else x++, sum += a[i].w1;
			} else if (y < n / 2){
				if (a[i].w2 < a[i].w3 && z < n / 2) z++, sum += a[i].w3;
				else y++, sum += a[i].w2;
			} else z++, sum += a[i].w3;
		}
		printf("%d", sum);
		cout << endl;
	}
	return 0;
}
