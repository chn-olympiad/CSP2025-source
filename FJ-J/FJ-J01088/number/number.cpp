#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
string s;
int sz,t[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s; sz=s.size(); s=' '+s;
	for(int i=1;i<=sz;i++)
		if(s[i]>='0'&&s[i]<='9')
			t[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=t[i];j++)
			cout<<i;
	return 0;
}
