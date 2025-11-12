#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int x[1005],ji=0;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			x[ji]=(int)(s[i]-'0');
			ji++;
		}
	}
	sort(x+0,x+ji);
	for(int i=ji-1;i>=0;i--)
	{
		cout<<x[i];
	}
	return 0;
} 
