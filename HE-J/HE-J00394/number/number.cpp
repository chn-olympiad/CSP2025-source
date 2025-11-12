#include<bits/stdc++.h>
using namespace std;

bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string n;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9'){
			n+=s[i];
		}
	}
	sort(n.begin(),n.end(),cmp);
	cout << n;
	return 0;
}
