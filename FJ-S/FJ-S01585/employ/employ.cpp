#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(long long i=0;i<n;i++){
		char ch;
		cin >> ch;
		if(ch=='0'){
			cout << 0;
			return 0;
		}
	}
	for(long long i=0;i<n;i++){
		long long c;
		cin >> c;
		if(c==0){
			cout << 0;
			return 0;
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans *= i;
		ans %= mod;
	}
	cout << ans;
	return 0;
}
