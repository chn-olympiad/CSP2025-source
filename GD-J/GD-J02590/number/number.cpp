#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,b[10];
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt++;
			b[s[i]-'0']+=1;
		}
	}
	for(int i=9;i>0;i--)
		for(int j=0;j<b[i];j++)
			cout<<i;
	for(int i=0;i<b[0];i++)
		cout<<0;
	return 0;
} 
