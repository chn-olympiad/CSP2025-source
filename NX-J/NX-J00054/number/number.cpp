#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int main()
{
	ifstream cin("number.in")
	ofstream cout("number.out")
	string s,s2=" ";
	cin>>s;
	char c,s1[10]={'1','2','3','4','5','6','7','8','9','0'};
	for(int i=0;i<s.length();i++)
	{
		for(int j=0;j<10;j++)
		{
			if(s[i]==s1[j])s2+=s[i];
		}
	}
	for(int i=0;i<s2.length();i++)
	{
		for(int j=0;i<s2.length()-1;j++)
		{
			if(s2[j]<s2[j+1])
			{
				c=s2[j];
				s2[j]=s2[j+1];
				s2[j+1]=c;
			}
		}
		
	}
	cout<<s2;
	return 0;
}
