#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
string s;
int len=0,a[10000010],t=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<=len-1;i++)
		if(s[i]>='0'&&s[i]<='9') a[++t]=s[i]-'0';
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--)
		cout<<a[i];
	cout<<endl;
	return 0;
}
