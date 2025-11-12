#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll _A(ll n){
	ll ans = 1; 
	for(ll i = 2;i <= n;i ++){
		ans = (ans * i) % 998244353;
	}
	return ans;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ll n,m;
	cin >> n >> m;
	ll kn = n;
	string s;
	cin >> s;
	for(int i = 1;i <= n;i ++){
		int x;
		cin >> x;
		if(!x) kn --;
	} 
	cout << _A(kn);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
