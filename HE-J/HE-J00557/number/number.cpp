#include<bits/stdc++.h>
using namespace std;
string s,p="";
//oiiaioiiiai
//sdsadsadsadsdsadasaaaaaaa
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(size_t i=0;i<s.size();i++)
	{
		if(isdigit(s[i])) p+=s[i];
	}
	sort(p.begin(),p.end(),cmp);
	cout<<p;
	return 0;
}
