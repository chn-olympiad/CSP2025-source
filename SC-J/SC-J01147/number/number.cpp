#include<bits/stdc++.h>
using namespace std;
long long ans[25];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(long long i = 0;i < s.size();i++){
		if('0' <= s[i] && '9' >= s[i]){
			ans[(long long)s[i] - 48]++;
		}
	}
	for(long long i = 9;i >= 0;i--){
		for(long long j = 1;j <= ans[i];j++){
			cout << i; 
		} 
	}
	return 0;
} 