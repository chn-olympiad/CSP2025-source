#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	long long n[15]={0};
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'){
			n[s[i]-'0']++;
		}
	}
	
	for(int i=9;i>=1;i--){
		while(n[i]!=0){
			cout<<i;
			n[i]--;
		}
	}
	
	return 0;
} 
