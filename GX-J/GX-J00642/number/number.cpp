#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
string s1;
string s2;
int len1,len2;
int main()
{
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
		getline(cin,s1);
		len1=s1.size();
		for(int i=0;i<=len1-1;i++)
		{
			cin>>s1[i];
			if(s1[i]>='0' && s1[i]=<'9')
				s2+=s1[i];
		}
		len2=s2.size();
		for(int i=0;i<=len2-1;i++)
		{
				if(s2[i]<=s2[i+1])
					swap(s2[i],s2[i+1]);
		}
		cout<<s2;
		return 0;
}
