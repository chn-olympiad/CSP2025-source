#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
using namespace std;
string s;
int len;
int n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=1;i<=len-1;i++)
		if(s[i]=='1' && s[i]=='2' &&s[i]=='3'&&s[i]=='4'&&s[i]=='5'&&s[i]=='6'&&s[i]=='7'&&s[i]=='8'&&s[i]=='9'&&s[i]=='0')
	cout<<s[i+1];
	return 0;
}
