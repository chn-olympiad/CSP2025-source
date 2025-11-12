#include<iostream>
#include<string>
using namespace std;

string s;
int a[10];
int main(){
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			for(int j=0;j<=9;j++){
				if(s[i]-'0'==j){
					a[j]++;
					break;
				}
			}
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
