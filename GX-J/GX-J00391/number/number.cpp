#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
string s;
int a[1000001];
int cnt=0,ans=0;
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
	for(int i=len-1;i>=0;i--)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[i]=s[i]-'0';	
			cnt++;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int j=0;j<=cnt-1;j++)
	{
		ans=ans*10+a[j];
	}
	cout<<ans;
	return 0;
}
