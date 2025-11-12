#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
string str;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	sort(str.begin(),str.end(),cmp);
	for(int i=0;i<(int)str.size();i++)
		if((str[i]>='0'&&str[i]<='9'))
			printf("%c",str[i]);
	return 0;
}
