#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	cin>>s;
	for(int i=0;i<s.size();){
		if('0'>s[i]||s[i]>'9'){
			s.erase(i,1);
		}
		else i++;
	}
	sort(s.begin(),s.end(),cmp);
	bool f=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='0'){
			f=1;
			break;
		}
	}
	if(!f){
		cout<<0;
		return 0;
	}
	cout<<s;
	return 0;
}