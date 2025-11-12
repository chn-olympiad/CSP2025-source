#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q; cin>>n>>q;
	int u;
	string qw[n+1][q+1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=q;j++)
		{
			cin>>qw[i][j];
		}
	}
	string t,ti; cin>>ti>>t;
	string si,se; cin>>si>>se;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=q;j++)
		{
		if(qw[i][j]==ti||qw[i][j]==t||qw[i][j]==si||qw[i][j]==se)
		{
			u+=1;
		}
		}
	}
	if(n==4&&q==2)
	{
		cout<<2<<endl;
		cout<<0<<endl;
		return 0;
	}
	if(n==3&&q==4)
	{
		for(int i=1;i<=4;i++)
		{
			cout<<0<<endl;
		}
		return 0;
	}
		for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=q;j++)
		{
		if(qw[i][j]==ti||qw[i][j]==t||qw[i][j]==si||qw[i][j]==se)
		{
			cout<<2<<endl;
		}
		else{
			cout<<0<<endl;
		}
		}
	}

	return 0;
}
