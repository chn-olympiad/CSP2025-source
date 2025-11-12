#include<iostream>
#include<string>
using namespace std;
int a[11],n;
int main(){
	//freopen("number.in");
	//freopen("number.out");
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=0;j<=a[i];j++){
				n=n*10+i;
				a[i]--;
			}
		}
	}
	cout<<n;
	return 0;
} 
