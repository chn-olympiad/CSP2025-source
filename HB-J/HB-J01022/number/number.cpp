#include <bits/stdc++.h>
using namespace std;
string s;
int ans[1000005],cnt;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++)
		if(s[i]>='0' && s[i]<='9')
			ans[++cnt]=s[i]-'0';
	sort(ans+1,ans+1+cnt,cmp);
	for(int i=1;i<=cnt;i++) cout<<ans[i];
	return 0;
}
