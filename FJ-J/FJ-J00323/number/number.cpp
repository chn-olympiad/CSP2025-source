#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,o="";
	cin >> s;
	int ns[10]={0,0,0,0,0,0,0,0,0,0};
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ns[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=ns[i];j++){
			o+=('0'+i);
		}
	}
	cout << o;
	return 0;
}
