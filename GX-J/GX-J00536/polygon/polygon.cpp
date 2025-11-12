#include<bits/stdc++.h>
using namespace std;
long long a,b[10000000],c,d[10000000];
void dfs(long long a1,long long a2,long long a3)
{
	if(a1==a2+1)
	{
		long long e=0,f=0;
		for(int i=1;i<=a2;i++)
		{
			e+=d[i];
			f=max(d[i],f);
		}
		if(e>f*2)
		{
			c++;
		}
		c%=998244353;
		return;
	}
	else if(a1==a2+2)
	{
		cout<<"You have no egg!";
	}
	for(int i=a3+1;i<=a-a2+a1;i++)
	{
		d[a1]=b[i];
		dfs(a1+1,a2,i);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b[i];
	}
	for(int i=3;i<=a;i++)
	{
		dfs(1,i,0);
	}
	cout<<c;
    return 0;
}
