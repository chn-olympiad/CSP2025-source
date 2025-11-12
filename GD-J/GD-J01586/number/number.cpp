#include<iostream>
#include<cstring>
#include<string> 
using namespace std;
string s;
int a[110];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size(),f=0;
	for(int i=0;i<l;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
			a[s[i]-'0']+=1;
	}
	for(int i=1;i<=9;i++)
		if(a[i]!=0)f=1;
	if(f==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
			cout<<i;
	}
	return 0;
}
