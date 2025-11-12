#include<bits/stdc++.h>
using namespace std;
string s;
int ans[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int c=s.length();
	for(int i=0;i<=c;i++)
	{
		int b;
		if(s[i]>=48&&s[i]<=57)
		{
			b=s[i]-48;
			ans[b]++;
		}
	}
	for(int i=9;i>=0;i--)
	for(int j=1;j<=ans[i];j++)
	cout<<i;
	return 0;
}
