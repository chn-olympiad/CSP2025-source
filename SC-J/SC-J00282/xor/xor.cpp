#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int l, r;
};
int n, k;
int a[500010];
int c[500010];
vector<node> q;
bool cmp(node x, node y){
	if(x.l == y.l) return x.r < y.r;
	return x.l < y.l;
}
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld %lld", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		c[i] = c[i - 1] ^ a[i];
		//cout << c[i] << " ";
	}
	//cout << endl;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int num = abs(c[j] - c[i - 1]);
			if(num == k) q.push_back({i, j}),i = j + 1;
			//cout << i << " " << j << " " << num << endl;
		}
	}
//	for(int i = 0; i < q.size(); i++){
//		if((q[i + 1].l >= q[i].l && q[i + 1].l <= q[i].r) || (q[i].r >= q[i + 1].l && q[i].r <= q[i + 1].r) && q[i].l != 0 && q[i].r != 0){
//			q[i + 1] = {0, 0};
//		}
//	}
	int cnt = 0;
	for(auto [x, y] : q){
		if(!x || !y)continue;
		else cnt++;
		//cout << x << " " << y << endl;
	}
	printf("%lld", cnt);
	return 0;
}
/*

*/