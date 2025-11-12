#include<iostream>
#include<string>
using namespace std;
int num[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;	
	cin>>s;
	for(int i=0;i<=sizeof(s);i++)
	{
		if('0'<=s[i] && '9'>=s[i])
		{
			num[s[i]-'0']++;
		}
	}
	
	for(int i=9;i>=0;i--)
	{
		//if(num[i]==0)continue;
		for(int j=1;j<=num[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
