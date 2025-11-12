#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=1e6+10;
int a[10];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		char c=s[i];
		if(c>='0'&&c<='9')
			a[c-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
			cout<<i;
	}
	return 0;
}
