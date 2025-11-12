#include<bits/stdc++.h>
#define int long long 
using namespace std;
string s;
int gh[1000005],h;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			gh[++h]=s[i]-'0';
		}
	}
	sort(gh+1,gh+1+h);
	for(int i=h;i>=1;i--)
	{
		cout<<gh[i];
	}
	return 0;	
}

