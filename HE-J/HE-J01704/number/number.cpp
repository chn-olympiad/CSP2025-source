#include<bits/stdc++.h>
using namespace std;

int ton[15];
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l = s.size();
	for(int i = 0;i < l;i++){
		if(s[i] <= '9'&&s[i] >= '0') ton[s[i]-'0']++; 
	}
	for(int i = 9;i >= 0;i--){
		while(ton[i]--) cout << i; 
	}
	return 0;
}
