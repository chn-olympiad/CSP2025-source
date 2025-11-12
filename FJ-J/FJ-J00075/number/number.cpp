#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<char,ll> mp;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<int(s.size());i++)
	if (s[i]>='0' && s[i]<='9')
	mp[s[i]]++;
	for (char i='9';i>='0';i--)
	while(mp[i]>0)
	cout<<i,mp[i]--;
	return 0;
}

