#include <bits/stdc++.h>
using namespace std;
string s;
int t[15];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	
	bool f=0;
	for (int i=9;i>=0;i--){
		if (i == 0 && !f){
			cout<<i;
			continue;
		}
		for (int k=1;k<=t[i];k++){
			cout<<i;
			f=1;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
