#include<bits/stdc++.h>
using namespace std;
int cnt[10];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s;
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			int num = s[i] - '0';
			cnt[num]++;
		}
	}
	string ans;
	for(int i = 9 ; i >= 0 ; i--){
		while(cnt[i] > 0){
			ans += i +'0';
			cnt[i]--;
		}
	}
	cout << ans;
	return 0;
}