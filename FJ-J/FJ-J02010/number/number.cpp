#include<bits/stdc++.h>
using namespace std;
string s;
bool f=0;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end(),cmp);
	int se=s.size(),si=0;
	while(s[si]>='a'&&s[si]<='z'&&si<se) si++;
	if(s[si]=='0'||si>=se) cout<<0;
	else cout<<s.substr(si);
	return 0;
}
