#include<bits/stdc++.h>
using namespace std;
int main(){

	string s, n = "";
	cin >> s;
	for(int i = 1;i <= s.size();i++){
		if(s[i] > s[i+1]){
			swap(s[i], s[i+1]);
		}
	}
    cout << s;
	return 0;
}
