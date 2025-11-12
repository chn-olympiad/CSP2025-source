#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
string s;
int len=0,ans[maxn];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]>='0'&&s[i]<='9') ans[++len]=s[i]-'0';
	}
	sort(ans+1,ans+len+1,cmp);
	for(int i=1;i<=len;++i) printf("%d",ans[i]);
	return 0;
}