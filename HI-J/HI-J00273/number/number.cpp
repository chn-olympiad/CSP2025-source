#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	//È¡Êı×Ö
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[i]=s[i]-'0';
		}
		
	} 
	//ÅÅĞò
	sort(n,n+s.size(),cmp);
	for(int i=0;i<s.size();i++){
		cout<<n[i];
	}
	return 0;
}
