#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
string s;
int a[1000001];
int t=0;
bool px(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<=len-1;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			t++;
			a[t]=s[i]-'0';
		}
	}
	sort(a+1,a+t+1,px);
	for(int i=1;i<=t;i++)
		cout<<a[i];
	return 0;
}
