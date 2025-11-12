#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=9;i>=0;i--)
	for(int j=0;j<len;j++)
	{
		if(s[j]-48==i)
		printf("%d",i);
	}
	return 0;
}
