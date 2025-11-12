#include<bits/stdc++.h>
using namespace std;
int main(){
	
	//freopen(number.in, "r", stdin);
	//freopen(number.out, "w", stdout);
	
	long long l[15]={0};
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			l[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<l[i];j++){
			cout << i;
		}
	}
	
	
	return 0;
}
