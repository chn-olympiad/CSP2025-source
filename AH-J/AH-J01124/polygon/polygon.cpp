#include<bits/stdc++.h>
using namespace std;
long long n,maxx;
long long a[1005];
bool b[1005];
long long t;
void dfs(int x,int k,long long maxn,long long s)
{
	if(k>=3)
	{
		if(s>2*maxn)
		{
			t++;
			t%=998244353;
		}
	}
	for(int i=x;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			dfs(i,k+1,max(maxn,a[i]),s+a[i]);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx==1)
	{
		int kkk=1,ttt=0;
		for(int i=3;i<=n;i++)
		{
			kkk=1;
			for(int j=n;j>n-i;j--)
			{
				kkk*=j;
				kkk%=998244353;
			}
			for(int j=2;j<=i;j++)
				kkk/=j;
			ttt+=kkk;
		}
		cout<<ttt<<endl;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<t;
}

