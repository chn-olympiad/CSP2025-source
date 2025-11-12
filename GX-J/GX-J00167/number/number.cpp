#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,t="";
	cin>>s;
	for(char x:s){if(x>='0' and x<='9')t+=x;}
	sort(t.begin(),t.end(),cmp);
	cout<<t;
	return 0;
}
