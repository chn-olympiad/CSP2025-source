#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s="";
	string s1="";
	int len=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			s1=s1+s[i];
		}
	}
	len=s1.size();
	for(int i=1;i<=len;i++)
	{
		for(int j=0;j<len;j++)
		{
			if(s1[j]<s1[j+1]&&j!=len-1)
			{
				swap(s1[j],s1[j+1]);
			}
		}
	}
	cout<<s1;
	return 0;
}