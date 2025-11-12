#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000005],l;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9') ans[++l]=(s[i]-'0');
	}
	sort(ans+1,ans+l+1,cmp);
	for(int i=1;i<=l;i++)
	{
		cout<<ans[i];
	}
	cout<<"\n";
	return 0;
}
