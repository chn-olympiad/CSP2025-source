#include<bits/stdc++.h>
using namespace std;
int t[10000000];
int main(){
	//freopen("number.in","s");
	//freopen("number.out","a");
	string s;
	cin>>s;
	if(s.size()==1){
		int q=s[0]-'0';
		cout<<q;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			t[i+1]=s[i]-'0';
		}
	}
	string a=" ";
	sort(t+1,t+s.size()+1);
	for(int i=1;i<=s.size;i++){
		a=a+char(t[i]+'0');
	}
	cout<<a;
	
	
	return 0;
}
