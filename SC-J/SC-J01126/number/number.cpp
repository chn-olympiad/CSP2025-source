#include <bits/stdc++.h>
using namespace std;
char n[1000005];
string s,ans="";
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	for (int i=0;i<s.length();i++)
		if (s[i]>='0'&&s[i]<='9')
			n[++cnt]=s[i];
	sort(n+1,n+cnt,cmp);
	for (int i=1;i<=cnt;i++)
		ans+=n[i];
	cout<<ans;
	return 0;
}
