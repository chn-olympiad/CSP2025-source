#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream cin("number.in");
	ofstream cout("number.out");
	
	string s;
	cin>>s;
	string a[100001]={};
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i] = s[i];
		}	
	}
	int x = s.length();
	sort(a,a+1+x);
	for(int i=x;i>0;i--){
		cout<<a[i];
	}
	cin.close();
	cout.close();
	return 0;
}
