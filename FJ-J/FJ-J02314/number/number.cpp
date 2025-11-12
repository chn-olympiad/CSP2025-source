#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
	char c[100001];
	int cl=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			c[cl]=s[i];
			cl++;
		}
	}
	sort(c,c+cl);
	for(int i=cl;i>=0;i--)
	{
		cout<<c[i];
	}
	return 0;
}
