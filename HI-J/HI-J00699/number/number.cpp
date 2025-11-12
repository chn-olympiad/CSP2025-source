#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a=s.length();
	if(a==1){
		cout<<s;
		return 0;
	}
	else{
		for(int i=0;i<=s.length();i++){
		if(s[i]<97) cout<<s[i];
		}
	}
	return 0;
} 
