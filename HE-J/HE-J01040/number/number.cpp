#include <bits/stdc++.h>
using namespace std;
string s,s1;
int cnt[1100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;++i)
	{
		if(s[i]>='0'&&s[i]<='9') ++cnt[(s[i]-'0')];
	}
	for(int i=9;i>=0;--i)
	{
		for(int j=1;j<=cnt[i];++j) s1+=(i+'0');
	}
	cout<<s1;
	return 0;
}
