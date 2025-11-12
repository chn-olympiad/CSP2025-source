#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int a[1000010],num=0;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<=len-1;i++)
	{
		if(s[i]=='0')	a[++num]=0;
		if(s[i]=='1')	a[++num]=1;
		if(s[i]=='2')	a[++num]=2;
		if(s[i]=='3')	a[++num]=3;
		if(s[i]=='4')	a[++num]=4;
		if(s[i]=='5')	a[++num]=5;
		if(s[i]=='6')	a[++num]=6;
		if(s[i]=='7')	a[++num]=7;
		if(s[i]=='8')	a[++num]=8;
		if(s[i]=='9')	a[++num]=9;
	}
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++)
		cout<<a[i];
	return 0;
}
