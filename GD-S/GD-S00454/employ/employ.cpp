#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long fastpow(int a,int b){
	long long res = 1;
	for(int i = 1;i <= a;i++){
		res *= b;
		res %= mod;
	}
	return res;
}
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt = 0;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 0;i < n;i++)if(s[i] == '1')cnt++;
	cout << fastpow(cnt,m) - m;
	
	
	return 0;
}
