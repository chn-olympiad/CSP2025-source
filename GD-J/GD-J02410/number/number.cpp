#include<bits/stdc++.h>
using namespace std;
string s;
int a[1005000],k,ans;
bool cmp(int l,int w)
{
	return l>w;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}
