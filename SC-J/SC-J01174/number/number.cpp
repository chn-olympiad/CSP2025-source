#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll n,a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n = s.length();
	for(int i = 0;i < n;i++){
		if('0' <= s[i] && s[i] <= '9'){
			a[s[i] - '0']++;
		}
	}
	for(int i = 9;i >= 0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}