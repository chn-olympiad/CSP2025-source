#include<bits/stdc++.h>
using namespace std;
string num;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num+=s[i];
		}
	}
	sort(num.begin(),num.end());
	for(int i=num.length()-1;i>=0;i--)
	{
		cout<<num[i];
	}
}