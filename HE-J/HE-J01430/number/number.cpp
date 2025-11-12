#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int ans=0;
int a[1000010];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ans++;
			a[ans]=s[i]-'0';
		}
	}
	sort(a+1,a+1+ans);
	for(int i=ans;i>0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
