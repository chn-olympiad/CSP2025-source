#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	string str_int = "";
	for (unsigned int i = 0;i < s.size();i ++){
		if ('0' <= s[i] and s[i] <= '9') str_int += s[i];
	}
	sort(str_int.begin(),str_int.end());
	reverse(str_int.begin(),str_int.end());
	cout << str_int;
	return 0;
}
