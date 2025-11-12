#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;cin >> s;
	sort(s.begin(),s.end(),greater<int>());
	int pos = 0;
	while(s[pos] < '0' || s[pos] > '9')pos++;
	s = s.substr(pos);
	int cnt = 0;
	for(auto x : s){
		if(x == '0')cnt++;
	}
	if(cnt == s.size())cout << "0";
	else cout << s;
	return 0;
} 
