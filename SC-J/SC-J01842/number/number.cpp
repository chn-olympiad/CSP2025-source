#include <bits/stdc++.h>
using namespace std;
string s;
int as[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			as[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(as[i]!=0)
		{
			int j=as[i];
		    while(j>0)
		    {
			  cout<<i;
			   j--;
		    }
		}
	}
}