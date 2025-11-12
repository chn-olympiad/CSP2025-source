#include<bits/stdc++.h>
using namespace std;
string s,ns;
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ns+=s[i];
		}
	}
	sort(ns.begin(),ns.end(),cmp);
	cout<<ns;
	return 0;
}
