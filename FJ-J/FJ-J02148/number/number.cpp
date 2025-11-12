#include<bits/stdc++.h>
using namespace std;
int t,a[1000005];
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
	for(int i=0;i<(int)s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			t+=1;
			a[t]=s[i]-'0';
		}
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++)
	{
		cout<<a[i];
	}
	return 0;
}
