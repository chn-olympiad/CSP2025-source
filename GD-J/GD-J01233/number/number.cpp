#include<string>
#include<iostream>
using namespace std;

string s;
int n,a[11];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> s;n = s.size();
	for(int i = 0;i < n;++i)
		if('0' <= s[i] && s[i] <= '9') ++a[s[i]-'0'];
	if(!a[1] && !a[2] && !a[3] && !a[4] && !a[5] && !a[6] && !a[7] && !a[8] && !a[9]){cout << 0;return 0;}
	for(int i = 9;i >= 0;--i)
		while(a[i]--) cout << i;
	return 0;
}
