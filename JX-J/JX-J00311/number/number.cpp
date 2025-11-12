#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s,a;
bool cmp(char a,char b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (char c : s){
		if (c <= '9' && '0' <= c){
			a += c;
		}
	}
	sort(a.begin(),a.end(),cmp);
	cout << a;
	return 0;
}