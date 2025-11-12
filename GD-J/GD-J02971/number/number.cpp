#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

bool cmp(char a,char b)
{
	return a>b; 
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,t="";
	cin >> s;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]>='0' && s[i]<='9')
			t+=s[i];
	}
	sort(t.begin(),t.end(),cmp);
	if (t[0]=='0' || t.empty())
		cout << 0;
	else
		cout << t; 
	return 0;
}
