#include<bits/stdc++.h>
using namespace std;
string s;
long long ans[1001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ans[(s[i]-'0')]++;
		}
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

