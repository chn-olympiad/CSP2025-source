#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]--){
			cout<<i;
		}
	}
	return 0;
}
/*
5

5

290es1q0

92100

2ksjeido

2

qwe0rty1yui2iop3asd4fhg5hjk6jlk7zc7vnb9bmn8

98776543210

99998888887777766666655555544444433332111000000000
99998888887777766666655555544444433332111000000000
*/
