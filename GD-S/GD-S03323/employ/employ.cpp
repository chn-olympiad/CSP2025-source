#include<bits/stdc++.h>
using namespace std;
string s;
int c,n,m;
const int mod = 998244353;
long long step(long long x){
	long long res = 1;
	for(int i = x ; i >= 1 ; i--){
		res*=i;
		res%=mod;
	}
	return res%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m ;
	cin >> s;
	for(int i = 1 ; i <= n ; i++)cin>>c;
	cout << step(n); 
	
	
	return 0;
}
