#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define isdigit(x) ((x) >= '0' && (x) <= '9')
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s,t = "";
	cin >> s;
	for(auto ch : s) if(isdigit(ch)) t.push_back(ch);
	sort(t.begin(),t.end(),greater<char> ());
	if(t[0] == '0') cout << "0";
	else cout << t;
	return 0;
}