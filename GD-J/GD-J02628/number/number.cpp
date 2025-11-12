#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000005];
int cnt=0;
bool cmp(int a1,int a2)
{
	return a1>a2;
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
			n[++cnt]=s[i]-'0';
		}
	}
	sort(n+1,n+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		cout<<n[i];
	}
 } 
