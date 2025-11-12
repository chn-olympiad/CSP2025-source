#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int c[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		//cout<<c[i];
		for(int j=0;j<c[i];j++){
			cout<<i;
		}
	}
	return 0;
}
