#include<iostream>
using namespace std;
int num[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int n,i,m,j,k;
	string s;
	cin>>s;
	for(i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			num[s[i]-'0']++;
		}
	}
	for(i=9;i>=0;i--)
	{
		for(j=1;j<=num[i];j++)
		{
			cout<<i;
		}
	}
	
	return 0;
 } 
