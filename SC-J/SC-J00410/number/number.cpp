#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],cnt;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1,greater <int>());
	if(a[1]==0) 
	{
		cout<<0;
	}
	else
	{
		for(int i=1;i<=cnt;i++) cout<<a[i];
	}
	return 0;
}