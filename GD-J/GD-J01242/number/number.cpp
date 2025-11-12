#include<bits/stdc++.h>

using namespace std;
int cot[15]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;cin>>s;s=" "+s; 
	for(int i=1;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cot[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cot[i];j++){
			printf("%d",i);
		}
	}
	return 0;
} 
