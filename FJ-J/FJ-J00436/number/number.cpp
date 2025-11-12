#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string s;
int n;
int t[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n = s.size();
	s = " " + s;
	bool f = 0;
	for(int i = 1;i<=n;i++){
		if(s[i]>='0' && s[i]<='9')t[s[i]-'0']++;
		if(s[i]>='1' && s[i]<='9')f = 1;
	}
	if(!f){
		cout<<0;
		return 0;
	}
	for(int i = 9;i>=0;i--){
		while(t[i]--)printf("%d",i);
	}
	return 0;
}
