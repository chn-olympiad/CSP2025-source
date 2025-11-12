#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int m[10]={0},n=1;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
			m[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		for(int j=0;j<m[i];j++)
			cout<<i;}
	return 0;}