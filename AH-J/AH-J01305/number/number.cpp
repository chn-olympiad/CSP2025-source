#include<bits/stdc++.h>
using namespace std;
string s;
string str;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			str+=s[i];
		}
	}
	sort(str.begin(),str.end());
	reverse(str.begin(),str.end());
	cout<<str;
	return 0;
}
