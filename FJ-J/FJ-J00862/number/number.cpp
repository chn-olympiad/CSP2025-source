#include<bits/stdc++.h>
#include<string>
using namespace std;
string s;
int t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i<s.length();i++)if('0'<=s[i]&&s[i]<='9')t[s[i]-'0']++;
	
	
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<t[i];j++)cout<<i;
	}
	return 0;
}