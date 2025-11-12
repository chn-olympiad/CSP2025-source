#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &i:v) cin >> i;
	
	long long ans = 0;
	for(int st=0;st<(1<<n);st++){
		if(__builtin_popcount(st)<=2) continue;
		int mxn = 0,sum = 0;
		for(int stp = st;stp;stp &= stp-1){
			int p = __builtin_ctz(stp);
			mxn = max(mxn,v[p]);
			sum = sum + v[p];
		}
		if(sum > 2*mxn) ans = (ans + 1)%mod;
	}
	
	cout << ans << '\n';
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
