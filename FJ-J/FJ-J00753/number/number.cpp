#include<cstring>
#include<iostream>
using namespace std;
string s;
int num[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			num[s[i]-'0']++;
		}
	}
	int flag=0;
	for(int i=9;i>=0;i--)
	{
		for(int j=num[i];j>=1;j--)
		{
			cout<<i;
		}
	}
	return 0;
}
