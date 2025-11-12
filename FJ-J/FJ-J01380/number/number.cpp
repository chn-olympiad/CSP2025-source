#include <bits/stdc++.h>
using namespace std;
string s;
char  a[1000005];
int ans[1000005];
int la;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ans[la]=s[i]-'0';
			la++;
		}
	}
	sort(ans,ans+la,cmp);
	for(int i=0;i<la;i++)
	{
		a[i]=ans[i]+'0';
	}
	for(int i=0;i<la;i++)
	{
		cout<<a[i];
	}
	return 0;
}
