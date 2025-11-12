#include <bits/stdc++.h>
using namespace std;
struct node{
	int a[4], num;
}q[100005];
int t, n, s[4], fl, ans;
bool cmp(node x, node y){
	if(x.a[1] == y.a[1]){
		if(x.a[2] == y.a[2])return x.a[3] > y.a[3];
		return x.a[2] > y.a[2];
	}
	return x.a[1] > y.a[1];
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ans = 0;
		scanf("%d", &n);
		fl = n / 2;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j < 4; j++){
				scanf("%d", &q[i].a[j]);
				q[i].num = i;
			}
		}
		sort(q + 1, q + 1 + n, cmp);
		for(int i = 1; i <= n; i++){
			int maxx = -1, d = 0;
			for(int j = 1; j < 4; j++){
				if(q[i].a[j] > maxx){
					d = j;
					maxx = q[i].a[j];
				}
			}
			if(d && s[d] >= fl)q[i].a[d] = -9, i--;
			else if(d){
				s[d]++;
				ans += maxx;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

