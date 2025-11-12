#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	string n,m,s,c;
	cin>>s;
	m[0] = s[0];
	for(int j = 0; j<=s.size();j++)
	{
		for(int i = 0; i<=s.size()+1;i++)
		{
			if(s[i]>m[0]&&s[i]>='0'&&s[i]<='9')
			{
				m[0] = s[i];
				s[i] = 'q';
			}
		}
		if(m[0]>='0'&&m[0]<='9')
			c+=m[0];
		m[0] = '.';
	}
	cout<<c;
	return 0; 
}
