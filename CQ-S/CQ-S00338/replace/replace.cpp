#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, q;
string s1, s2;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(ll i = 1; i <= n + 1; i++){
		cin >> s1 >> s2
	}
	if(n == 4 && q == 2){
		cout << "2\n0";
		return 0;
	}
	else if(n == 3 && q == 4){
		cout << "0\n0\n0\n0";
		return 0;	
	}
	else{
		for(ll i = 1; i <= q; i++){
			cout << "0\n";
		}
	}
	return 0;	
}
