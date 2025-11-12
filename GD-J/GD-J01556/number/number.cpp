#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			mp[s[i]]++;
		}
	}
	for(char i='9';i>='0';i--)
	{
		while(mp[i])
		{
			cout<<i;
			mp[i]--;
		}
	}
	return 0;
} 
