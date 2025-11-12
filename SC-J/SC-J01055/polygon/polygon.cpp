#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10000005];
const int MOD=998244353;
int c(int n, int x){
	int A=1, B=1, C=1;
	for(int i=1;i<=n;i++){
		A*=i;
	}
	for(int i=1;i<=x;i++){
		B*=i;
	}
	if(x==n){
		C=1;
	}else{
		for(int i=1;i<=n-x;i++){
			C*=i;
		}
	}
	return A/(B*C);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, ans=0, all=0, mx=-1e9;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		mx=max(mx, a[i]);
		all+=a[i];
	}
	if(n<=2){
		cout << 0;
		return 0;
	}else if(n==3){
		if(mx*2<all){
			cout << 1;
			return 0;
		}else{
			cout << 0;
			return 0;
		}
	}else{
		for(int i=3;i<=n;i++){
			ans+=c(n, i);
			ans%=MOD;
		}
		cout << ans%MOD;
	}
	return 0;
}