#include<bits/stdc++.h>
using namespace std;

const int N=5500;
const int modd=998244353;

int n;
long long ans;
int a[N];

void dfs(int x,int sum,int cnt,int maxn)
{
	if(x==n+1)
	{
		if(cnt>2&&sum>2*maxn)ans=(ans+1)%modd;
		return ;
	}
	dfs(x+1,sum+a[x],cnt+1,max(maxn,a[x]));
	dfs(x+1,sum,cnt,maxn);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;

	for(int i=1;i<=n;i++)
	{	
		cin>>a[i];	
	}

	if(n<=100)dfs(1,0,0,0);
	else for(int i=n-2;i>0;i--)ans=(ans+i)%modd;

	cout<<ans;

	return 0;
}

