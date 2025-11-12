#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
string s,t="";
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++)if (s[i]>='0'&&s[i]<='9')t+=s[i];
	sort(t.begin(),t.end(),cmp);
	cout<<t<<endl;
	return 0; 
}
