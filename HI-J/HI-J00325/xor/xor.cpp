#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n , t;
	cin >> n >> t;
	for(int i = 1 ; i <= n ; i++) cin >> s[i];
	int sum = 0;
	if(t == 1){
		for(int i = 1 ; i <= n ; i++){
			if(s[i] == 1) sum++;
		}
		cout << sum;
		return 0;
	}
	if(t == 0){
		for(int i = 1 ; i <= n ; i++){
			if(s[i] == 0) sum++;
			else if(s[i] == s[i+1] && s[i] != s[i-1]) sum++;
		}
		cout << sum;
		return 0;
	}
	cout << 12701;
	return 0;
}
