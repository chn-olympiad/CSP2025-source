#include<bits/stdc++.h>
using namespace std;
int n,f=1;
string s,str[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			str[int(s[i]-48)]+=s[i];
		}
		if(s[i]>='1'&&s[i]<='9'){
			f=0;
		}
	}
	if(f==1){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		cout<<str[i];
	}
	return 0;
}
