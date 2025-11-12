#include<bits/stdc++.h>
using namespace std;
long long a,b,c[10000000],d[10000000],e[100][100];
void dfs(int a1,int a2,int a3,int a4)
{
	e[a1][a2]=d[a4];
	if(a4==a*b)
	{
		return;
	}
	if(b==a2&&a3==0)
	{
		dfs(a1+1,a2,1,a4+1);
	}
	else if(1==a2&&a3==1)
	{
		dfs(a1+1,a2,0,a4+1);
	}
	else if(a3==0)
	{
		dfs(a1,a2+1,0,a4+1);
	}
	else if(a3==1)
	{
		dfs(a1,a2-1,1,a4+1);
	}
	else
	{
		cout<<"You have no egg!";
	}
}
int z(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i++)
	{
		cin>>c[i];
		d[i]=c[i];
	}
	sort(d+1,d+1+a*b,z);
	dfs(1,1,0,1);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(e[i][j]==c[1])
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	cout<<"You have no egg!";
    return 0;
}
