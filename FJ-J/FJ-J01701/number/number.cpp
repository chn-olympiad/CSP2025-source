#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int s1,s2,s3,s4,s5,s6,s7,s8,s9;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s.size(i)==1)
		{
			s1++;
		}
        if(s.size(i)==2)
		{
			s2++;
		}
		if(s.size(i)==3)
		{
			s3++;
		}
		if(s.size(i)==4)
		{
			s4++;
		}
		if(s.size(i)==5)
		{
			s5++;
		}
		if(s.size(i)==6)
		{
			s6++;
		}
		if(s.size(i)==7)
		{
			s7++;
		}
		if(s.size(i)==8)
		{
			s8++;
		}
		if(s.size(i)==9)
		{
			s9++;
		}
	}
	cout<<endl;
	for(int i=1;i<=s1;i++)
	{
		cout<<1;
	}
	for(int i=1;i<=s2;i++)
	{
		cout<<2;
	}
	for(int i=1;i<=s3;i++)
	{
		cout<<3;
	}
	for(int i=1;i<=s4;i++)
	{
		cout<<4;
	}
	for(int i=1;i<=s5;i++)
	{
		cout<<5;
	}
	for(int i=1;i<=s6;i++)
	{
		cout<<6;
	}
	for(int i=1;i<=s7;i++)
	{
		cout<<7;
    }
	for(int i=1;i<=s8;i++)
	{
		cout<<8;
	}
	for(int i=1;i<=s9;i++)
	{
		cout<<9;
	}
	return 0;
}
