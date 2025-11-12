#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
string s;
string a;
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a+=s[i];
		}
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	cout << a;
	return 0;
} 
