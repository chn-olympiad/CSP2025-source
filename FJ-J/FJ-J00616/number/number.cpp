#include<iostream>
#include<string>
using namespace std;
int num[10]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[s[i]-'0']++;
		}
	}
//	for(int i=0;i<10;i++)
//	{
//		cout<<num[i]<<" ";
//	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<num[i];j++)
		{
			cout<<i;
		}
	}
}
