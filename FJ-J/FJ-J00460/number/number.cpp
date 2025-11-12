#include<bits/stdc++.h>
using namespace std;
int t[66];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	if(s.size()==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]]++;
		}
	}
	for(int i=65;i>=0;i--){
		if(t[i]>0){
			for(int j=1;j<=t[i];j++){
				cout<<char(i);
			}
		}
	}
	return 0;
} 
