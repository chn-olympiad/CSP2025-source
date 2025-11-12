#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i = 9;i >= 0;i--){
		char ch = '0' + i;
		while(s.find(ch) != -1){
			cout << i;
			s.replace(s.find(ch),1,"");
		}
	} 
	return 0;
}

