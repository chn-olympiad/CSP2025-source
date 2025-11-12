#include<bits/stdc++.h>
using namespace std;
void fre(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
bool isnum(char n){
	if(n>='0' && n<='9')return 1;
	return 0;
}
string s;
char num[1000010];
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fre();
	cin>>s;
	for(int i=0;i<s.size();i++){
		num[i]=1;
	}
	bool f;
	for(int i=0;i<s.size();i++){
		f=isnum(s[i]);
		if(f)num[i]=s[i];
	}
	sort(num,num+s.size(),greater<int>());
	for(int i=0;i<s.size();i++){
		f=isnum(num[i]);
		if(f)cout<<num[i];
	}
	cout<<endl;
	return 0;
}
//100pts




