#include<bits/stdc++.h>

using namespace std;
map<char, long long> v;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> s;
	for(int i = 0;i < s.size();i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			v[s[i]] ++;
		}
	}
	for(int i = 9;i >= 0;i --){
		while(v['0' + i]){
			cout << (char)('0' + i);
			v['0' + i] --;
		}
	}
	return 0;
}
