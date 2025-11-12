#include<bits/stdc++.h>

using namespace std;

string h(string s)
{
	char c;
	for(int i=0;i<s.length();i++)
	{
		for(int j=0;j<s.length();j++)
		{
			if( s[i]>s[j] )
			{
				c=s[i];
				s[i]=s[j];
				s[j]=c;
			}
		}
		
	}
	return s;
}

int main()
{
	//freopen("number.in","r",stdin)
	//freopen("number.out","w",stdout)
	
	string s,s1;
	cin>>s;
	
	for( int i =0;i<=s.length();i++)
	{
		if( s[i]<='9' && s[i]>='0')
		{
			s1+=s[i];
		}
	}
	cout<<h(s1);
	
	
	
	
	//fclose(stdin)
	//fclose(stdout)
	
	return 0;
} 
