#include<iostream>
using namespace std;

string s;
string s1[10];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			s1[s[i]-'0']+=char(s[i]);
		}
	}
	for(int i=9;i>=0;i--)
	{
		cout<<s1[i];
	}
	cout<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
