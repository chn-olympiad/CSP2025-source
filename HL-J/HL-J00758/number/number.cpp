#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s[1000010100101];
	for(int i=0;i<10000000000001;i++){
		cin>>s[i];
	}
	
	for(int i=0;i<1001001001010;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cout<<s[i];
		}
	}	

	return 0;
} 
