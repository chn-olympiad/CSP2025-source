#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,t;
	int cnt=0;
	cin>>s;
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]>='0' && s[i]<='9' && s.size()==1)
		{
			cout<<s[i];
			return 0;
		}
		if(s[i]>='0' && s[i]<='9')
		{
			t[i]=s[i];
			cnt++;
		}
		else continue;
	}
	for(int i=0; i<t.size(); i++)
	{
		if(t[i+1]>t[i])
		{
			swap(t[i+1],t[i]);
		}
	}
	cout<<t;
	return 0;
}
