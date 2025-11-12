#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,q;
	cin >> n >> m >> q;
	int a[n],ans = 0;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int j = 0;j<=m;j++){
		int cnt = 1;
		for(int i = 1;i<=n-j;i++){
			cnt *= i;
		}
		ans+=cnt;
	}
	cout << ans%998244353;
	return 0;
}
