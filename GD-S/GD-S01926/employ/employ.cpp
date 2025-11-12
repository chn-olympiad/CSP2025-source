#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n, m, a[505], f=1, sum[505];
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		char x;
		cin >> x;
		a[i]=x-'0';
		if(a[i]==1)f=0;
		sum[i]=sum[i-1]+a[i];
	}
	if(f==1){
		int ans=1;
		for(int i=1;i<=m;i++){
			ans=(ans*n)%mod;
			n--;
		}
		cout << ans << endl;
		return 0;
	}
	if(m==n){
		cout << 0 << endl;
		return 0;
	}
	if(sum[n]<m){
		cout << 0 << endl;
		return 0; 
	}
	return 0;
}
