#include<bits/stdc++.h>
using namespace std;
string s;
int book[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<'0'||s[i]>'9')continue;
		else book[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)while(book[i]--)cout<<i;
	return 0;
}
