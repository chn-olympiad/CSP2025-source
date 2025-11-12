#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,a;
bool cmp(char x,char y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ll minn = 1000000;
	cin >> s;
	sort(s.begin(),s.end(),cmp);
	for(ll i = 1;i <= 9;i++)
		if(s.find(i+'0') != string::npos)
			minn = min(ll(s.find(i+'0')),minn);
	cout << s.substr(minn,ll(s.size()-minn));
	return 0;
}
