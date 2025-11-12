#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int t[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]-'0'>=0&&str[i]-'0'<=9){
			t[str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(t[i]>0){
			cout<<i;
			t[i]--;
		}
	}
	return 0;
}