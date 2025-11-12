//number AC 1 2 3 4

#include<iostream>
#include<string>
using namespace std;
using ll = long long;
ll n[11]; //0-9的数字数量 
int main(){
	
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	
	bool all_zero = 1;
	for(int i = 0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			//if number
			n[s[i]-'0']++;
			//i数字加一 
			if(s[i]>'0')all_zero = 0;
		}
	}
	
	//全是0 
	if(all_zero){
		cout<<0;
		return 0;
	}
	
	for(int i = 9;i>=0;i--){
		for(int j = 0;j<n[i];j++){
			cout<<i;
		}
	}
}
