#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long num[10005];
	cin>>s;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;--i)
	{
		for(int j=1;j<=num[i];++j)
			cout<<i;
	}
	return 0;
}
