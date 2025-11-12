#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005, mod=998244353;
int n, a[N], ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<(1<<n);i++){
		int cnt=0, maxx=0, sum=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				sum++;
				cnt+=a[j+1];
				maxx=max(maxx,a[j+1]);
			}
		}
		if(cnt>maxx*2 && sum>=3){
			ans=(ans+1)%mod;
		}
	}
	cout << ans;
	return 0;
}
