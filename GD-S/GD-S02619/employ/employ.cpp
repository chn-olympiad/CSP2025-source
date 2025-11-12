#include<bits/stdc++.h>
using namespace std;

int n,m,flag;
string lvl;
int c[501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>lvl;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<lvl.size();i++)
	{
		if(lvl[i]!='1')flag=1;
	}
	if(!flag)
	{
		int x=n;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0)x--;
		}
		long long ans=1;
		for(int j=1;j<=x-m;j++)
		{
			ans*=j;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}

}

