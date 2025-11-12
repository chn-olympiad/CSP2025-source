#include<bits/stdc++.h>
using namespace std;
string s;
int num[10]={0},ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=' '+s;
	for(int i=1;i<s.size();i++){
		if(isdigit(s[i]))num[s[i]-'0']++;
	}
	int fg=0;
	for(int i=9;i>=0;i--){
		while(num[i]--)cout<<i;
	}
	return 0;
} 