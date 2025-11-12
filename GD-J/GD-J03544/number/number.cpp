#include<bits/stdc++.h>
using namespace std;
string s;
map<char, int> t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.length();i++)
	{
		t[s[i]]++;
	}
	for(char i='9';i>='0';i--)
	{
		for(int j=1;j<=t[char(i)];j++) cout << char(i);
	}
	return 0;
}
