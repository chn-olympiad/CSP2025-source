#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int s[10000];
int s1[11][11];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,a,q=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	a1=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(s[i]==a1)
		a=i;
	}
	
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				s1[i][j]=s[q];
				q++;
			}
		}
		else
		{
			for(int j=m;j>0;j--)
		{
			s1[i][j]=s[q];
			q++;
		}
		}
		
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s1[j][i]==a1)
			{
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
