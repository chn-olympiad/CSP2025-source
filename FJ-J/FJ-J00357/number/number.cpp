#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
char s[1000005];
int a[1000005];
char cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s,s+1000000,cmp);
	for(int i=1;i<=1000000;i++)
	{
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
		{
			cout<<s[i];
		}
	}
//	cout<<s;
	return 0;
}
