#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> s(n*m+1);
	cin>>s[1];
	int p=s[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>s[i];
	}
	sort(s.begin()+1,s.end(),greater<int>());
	int z=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=s[z];
			z++;
		}
	}
	int cou=1;
	for(int i=1;i<=m;i++)
	{
		if(cou%2==0)
		{
			sort(a[i]+1,a[i]+n+1);
		}
		else
		{
			sort(a[i]+1,a[i]+n+1,greater<int>());
		 } 
		 cou++;
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==p)
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
