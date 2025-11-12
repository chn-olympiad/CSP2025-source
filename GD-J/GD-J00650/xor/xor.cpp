#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
const int INF=0x3f3f3f3f, M=5e6+5;
int n, m, idx, tmp, ans, L;
int a[M], b[M];
struct node{
	int l, r;
	friend bool operator < (node x, node y){
		return x.r < y.r;
	}
}sq[M];
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m; L=1;
	for (int i=1; i<=n; i++) cin >> a[i], b[i]=a[i]^b[i-1];
	for (int i=1; i<=n; i++){
		for (int j=L; j<=i; j++){
			if ((b[i]^b[j-1]) == m) sq[++idx]={j, i}, L=i+1;
		}
	}
	sort(sq+1, sq+idx+1);
	tmp=sq[1].r, ans=1;
	for (int i=1; i<=idx; i++){
		if (sq[i].l > tmp){
			tmp = sq[i].r;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
 
