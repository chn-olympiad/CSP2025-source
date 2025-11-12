#include<bits/stdc++.h>
using namespace std;
int main(){
	char i;
	char s[100006];
	cin>>s;
	
	if(s[0]<s[1]){
		i=s[0];
		s[0]=s[1];
		s[1]=i;
	}
	if(s[0]>'9') cout<<s[1];
	else cout<<s;
	return 0;
}

