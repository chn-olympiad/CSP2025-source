#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int jiecheng(int x)
{
	int ans=1;
	for(int i=2;i<=x;i++)
	{
		ans*=i;
	}
	return ans;
}
int cnt;
int n,m;
int c[1003]; 
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			cnt++;
		}
	}
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	if(m>cnt)
	{
		cout<<0<<endl;
	}
	else
	{
		cout<<jiecheng(n)<<endl;
	}
	return 0;
}
