#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	getline(cin,s);
	int a[s.size()]={};
	int j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>'0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++; 
		}
	}
	sort(a,a+s.size(),cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;	
}
