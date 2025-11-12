#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],n;
int cmp(int a1,int b1)
{
	return a1>b1;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[++n]=s[i]-'0';
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		cout<<a[i];
	return 0;
}