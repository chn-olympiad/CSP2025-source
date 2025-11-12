#include<bits/stdc++.h>
using namespace std;
int x[17];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,word="";cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') x[s[i]-'0']++;
	}
	for(int i=10;i>=0;i--){
		if(x[i]!=0){
			while(x[i]--){
				char a=i+'0';
				word+=a;
			}
		}
	}
	cout<<word;
	return 0;
}
