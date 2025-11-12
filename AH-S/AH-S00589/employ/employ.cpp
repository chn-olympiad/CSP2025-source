#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, c[510], ans;
int cnt;
map<int, int> t;
string s;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++){
		cin>>c[i];
		t[c[i]]++;
	}
	for(int i=0; i<s.size(); i++){
		if(s[i] == '1') cnt++;
	}
	if(cnt == n){//al 1
		ans=0;
    	sort(c+1, c+1+n);
    	for(int i=1; i<=n; i++){
    		if(i-1<=c[i]) {
    			ans++;
    			ans%=mod;
    		}
    	}
    	cout<<ans<<endl;
    	return 0;
	}else{
		for(int i=1; i<=n; i++){
			ans = (ans+c[i])%mod;
		}
		ans = max(ans, cnt);
	}
	cout<<ans<<endl;
	return 0;
}