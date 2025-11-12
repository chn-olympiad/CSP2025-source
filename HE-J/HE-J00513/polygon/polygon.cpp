#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+100;
const int MOD=998244353;
int a[N];
int n;
int qpow(int x,int y) {
	int k=x;
	int res=1;
	while(y) {
		if(y&1) res=res*k%MOD;
		k=k*k%MOD;
		y=y/2;
	}
	return res;
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int ans=0;
	bool f=0;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) {
		if(a[i]!=1) f=1;
	}
	if(!f) {
		cout<<(qpow(2,n)-1-n-n*(n-1)/2+MOD)%MOD;
	} else {
		for(int i=0; i<(1<<n); i++) {
			int num=0;
			int sum=0;
			int ma=0;
			for(int j=1; j<=n; j++) {
				if((i>>(n-j))&1) {
					num++;
					sum+=a[j];
					ma=max(ma,a[j]);
				}
			}
			if(num>=3&&sum>2*ma) ans++,ans%=MOD;
		}
		cout<<ans;
	}
	return 0;
}
//the end
