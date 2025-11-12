#include <bits/stdc++.h>
using namespace std;
string s;
bool cmp(char a,char b){
	return  a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	string d = "";
	for(int i = 0; i < int(s.size()); ++i){
		if(s[i] >= '0' && s[i] <= '9'){
			d += s[i];
		}
	}
	sort(d.begin(),d.end(),cmp);
	cout << d;
	return 0;
}
