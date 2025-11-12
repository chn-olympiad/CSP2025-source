#include <bits/stdc++.h>
using namespace std;
const int PRO_MAX=500005;
int ans=0;
int n,k;
int a[PRO_MAX];
int dfs(int qi) {
	if(qi>n) {
		return 0;
	}
	if(a[qi]==k) {
		ans++;
//		cout<<qi;
		dfs(qi+1);
		return 0;
	}
	int lost=a[qi];
	for(int i=qi+1; i<=n; i++) {
		lost=lost xor a[i];
		if(lost==k) {
			ans++;
//			cout<< qi<<' '<<i<<' '<<lost<<endl;
			dfs(i+1);
			return 0;
		}
	}
	dfs(qi+1);
	return 0;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
