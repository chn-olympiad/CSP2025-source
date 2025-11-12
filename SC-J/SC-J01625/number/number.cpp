#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
bool cmp(int s1,int s2)
{
	return s1>s2;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int tot=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')a[++tot]=s[i]-'0';
	}
	sort(a+1,a+1+tot,cmp);
	if(a[1]==0)cout<<0;
	else 
	{
		for(int i=1;i<=tot;i++)
		{
			cout<<a[i];
		}
	}
	return 0;
}