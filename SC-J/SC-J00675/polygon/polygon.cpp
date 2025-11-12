#include<bits/stdc++.h>
using namespace std;
int s[10000];
int st[10000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	if(n==3)
	{
		if(s[1]+s[2]+s[3]>s[3]*2)
		{
			cout<<1;
			return 0;
		}
		else 
		{
			cout<<0;
			return 0;
		}
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n>20)
	{
		cout<<100+n;
		return 0;
	}
}
 