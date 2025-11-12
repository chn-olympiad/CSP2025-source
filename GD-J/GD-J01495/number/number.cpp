#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int k=0;k<s.size();k++)if(s[k]>='0'&&s[k]<='9')mp[s[k]]++;
	for(auto k:mp)for(int i=1;i<=k.second;i++)a+=k.first;
	reverse(a.begin(),a.end());
	cout<<a;
	return 0;
} 
