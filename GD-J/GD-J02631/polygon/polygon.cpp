#include<bits/stdc++.h>
using namespace std;

const int N = 5e3+10;
const int M = 998244353;
int a[N], n, ans;

void dfs(int l, int x, int sm, int mx){
//	printf("%d %d %d %d ", l, x, sm, mx);
	if(l<=1) {
		if(sm+a[x]>max(mx, a[x])*2) {
			ans++;
			ans%=M;
//			cout << "ok";
		}
//		cout << '\n';
		return;
	}
//	cout << '\n';
	for(int i=x+1;i<=n;i++) dfs(l-1, i, sm+a[x], max(mx, a[x]));
}

signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	bool flag = 1; // ai=1
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		if(a[i]!=1) flag = 0;
	}
	if(flag){
		// 15 ~ 20
		long long awa=0;
		for(int i=3;i<=n;i++){
			long long tmp=1;
			int j = i, k=n;
			int divs[N];
			memset(divs, -1, sizeof(divs));
			int divcnt = 0;
			while(j--){
				tmp*=(k--);
				divs[divcnt++] = j+1;
				for(int waw = 0;waw<divcnt;waw++){
					if(divs[waw]==-1||divs[waw]==0) continue;
					if(tmp%divs[waw]==0) tmp/=divs[waw];
				}
				tmp%=M;
			}
			awa+=tmp;
			awa%=M;
		}
		cout << awa;
		return 0;
	}
	for(int l=3;l<=n;l++){
		for(int i=1;i<=n;i++){
			dfs(l, i, 0, 0);
		}
	}
//	dfs(3, 2, 0, 0);
	cout << ans;
	
	return 0;
}
