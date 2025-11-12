#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a));
	bool other_=false; 
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			if(s[i]>'0')other_=true;
			++a[s[i]-'0'];
		}
	}
	if(!other_)cout<<"0";
	else{
		for(int i=9;i>=0;i--){
			while(a[i]){
				cout<<i;
				--a[i];
			}
		}
	}
	return 0;
}
