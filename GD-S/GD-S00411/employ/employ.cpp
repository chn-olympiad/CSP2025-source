#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1004;
const int mod = 998244353;

int n,m;
string s;
int c[maxn];

ll re(){
	ll ans = 1;
	for(int i=n;i>n-m;i--){
		ans *= i;
		ans %= mod;
	}
	return ans;
}


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	bool flag = 0;
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')
			flag = 1;
	}
	if(!flag){
		ll ans = 1;
		ans = re();
		
		cout << ans << endl;
		return 0;
	}
	
	if(m==1){
		ll ans = 1;
		ans = re();
		cout << ans << endl;
		//cout << n << " " << m << endl;??

	}
	if(m==n){
		if(flag){
			cout << 0 << endl;
		} else {
			ll ans = re();
			cout << ans << endl;
		}
	}
	
	
	
	return 0;
	
} 
