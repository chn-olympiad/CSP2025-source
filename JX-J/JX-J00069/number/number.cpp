#include<bits/stdc++.h>
using namespace std;
int a[20];
string s,s1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{	
			s1+=char(i+48);
		}
	}
	cout<<s1<<endl;
	return 0;
}
