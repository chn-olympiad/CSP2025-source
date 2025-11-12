#include <bits/stdc++.h >
using namespace std;
string s;
int a[100000000];
int main(){
	cin>>s;
	if(s.size()==1){
		cout<<s;
		return 0; 		
	}
	int z=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			a[++z]=s[i]-'0';
		}
	}
	sort(a+1,a+1+z);
	for(int i=z;i>=1;i--){
		cout<<a[i];
	}
}