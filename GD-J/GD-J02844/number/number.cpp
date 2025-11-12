#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll cnt[15];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> s;
	memset(cnt, 0, sizeof(cnt));
	for(int i=0; i<=s.size()-1; i++){
		if(s[i] == '0') cnt[0]++;
		if(s[i] == '1') cnt[1]++;
		if(s[i] == '2') cnt[2]++;
		if(s[i] == '3') cnt[3]++;
		if(s[i] == '4') cnt[4]++;
		if(s[i] == '5') cnt[5]++;
		if(s[i] == '6') cnt[6]++;
		if(s[i] == '7') cnt[7]++;
		if(s[i] == '8') cnt[8]++;
		if(s[i] == '9') cnt[9]++;
	}
	for(int i=9; i>=0; i--){
		for(int j=1; j<=cnt[i]; j++){
			cout << i;
		}
	}
	return 0;
}

