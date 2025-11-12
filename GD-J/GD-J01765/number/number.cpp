#include<bits/stdc++.h>
using namespace std;
int a[1000005],n=0;
string s;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			n++;
			a[n]=s[i]-'0';
		}
	}

	sort(a+1,a+n+1,cmp);
	if(a[1]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cout<<a[i];
	
	
	
	
	
	return 0;
}
