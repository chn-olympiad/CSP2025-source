#include<bits/stdc++.h>
using namespace std;
string s;
int ans[200],k2;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int x;
	cin>>s;
	int len=s.size();
	for(int i=0;i<=len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			x=s[i]-'0';
			if(x!=0) k2=1;
			ans[x]++;
		}
	}
	if(k2==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--)
	{
		while(ans[i]>0)
		{
			cout<<i;
			ans[i]--;
		}
	}
	return 0;
} 
