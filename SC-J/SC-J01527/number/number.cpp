#include<bits/stdc++.h>
using namespace std;
#define int long long

string s,a;
int dig[15];
bool flg;

signed main(void)
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			dig[s[i]-'0']++;
			if(s[i]!='0')flg=true;
		}
	}
	if(!flg)cout<<0<<endl;
	else
	{
		for(int i=9;i>=0;i--)
		{
			for(int j=1;j<=dig[i];j++)
				cout<<i; 
		}
	}
	cout<<endl;
	return 0;
}
