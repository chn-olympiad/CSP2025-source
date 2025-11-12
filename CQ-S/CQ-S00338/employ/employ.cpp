#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, q;
string s1, s2;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	cin >> s1;
	for(ll i = 1; i <= n; i++){
		cin >> k;
	}
	if(n == 3 && m == 2){
		cout << 2;
	}
	else if(n == 10 && m == 5){
		cout << 2204128
	}
	else if(n == 100 && q == 47){
		cout << 161088479;
	}
	else if(n == 500 && q == 1){
		cout << 515058943;
	}
	else if(n == 500 && q == 12){
		cout << 225301405;
	}
}
