#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,tmp="";
	cin>>s;
	for(int i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')tmp+=s[i];
	sort(tmp.begin(),tmp.end(),cmp);
	if(tmp[0]=='0')cout<<"0\n";
	else cout<<tmp<<"\n";
	return 0;
}
