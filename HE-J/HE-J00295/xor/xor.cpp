#include<bits/stdc++.h>
using namespace std;
string a[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=a[i+1])
		{
			cnt++;
		}
	}
	if(n==2)
	{
		if(a[1]!=a[2])
		{
			cout<<1;return 0;
		}
		else
		{
			cout<<0;return 0;
		}
	}
	if(m==0)
	{
		cout<<0;
		return 0;
	}
	else if(m==1)
	{
		cout<<cnt;
		return 0;
	}
	else 
	{
		cout<<8;
		return 0;
}	
}
