#include "bits/stdc++.h"
using namespace std;
vector<int> ct(10,0);
int main(){
	
	cin.tie(nullptr);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ct[s[i]-'0']++;
		}
	}
	
	for(int i=9;i>=0;i--){
		for(int j=1;j<=ct[i];j++){
			printf("%d",i);
		}
	}
	return 0;
} 