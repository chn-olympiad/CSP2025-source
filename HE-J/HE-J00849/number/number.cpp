#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,c="";
	std::cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9' and s[i]>='0')
		{
			c+=s[i];
		}
	}
	std::sort(c.begin(),c.end());
	for(int i=c.size()-1;i>=0;i--)
	{
		std::cout<<c[i];
	}
	return 0;
}//·ð×æ±£ÓÓ
//9:__ __ 
