#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e6+5;
int tot[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string s;cin >> s;
	for (int i=0;i<s.size();++i){
		if (s[i]>='0' && s[i]<='9') ++tot[s[i]];
	}
	for (int i='9';i>='0';--i){
		for (;tot[i];--tot[i]) cout<<(((char)i));
	}
	cout.flush();
	return 0;
}
/*
I'm xiaoyang111(luogu:1220111/890311)
表里山河起尘埃
I'll AK CSP-J!
jfjfjfjf
jfjfjfjf
jfjfjfjf
jfjfjfjf
jfjfjfjf
jfjfjfjf
jfjfjfjf
jfjfjfjf
*/