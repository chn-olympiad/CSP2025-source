#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//freopen("number4.in","r",stdin);
	//freopen("number4.out","w",stdout);
	string s;
	cin >> s;
	vector<char> num;
	for(const char &ch : s) if(isdigit(ch)) num.push_back(ch);
	sort(num.begin(),num.end(),greater<>());
	for(const char &ch : num) putchar(ch);
	return 0;
}