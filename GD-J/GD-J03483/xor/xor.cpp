#include<bits/stdc++.h>
using namespace std;
int n,x,a[1000000],ans=INT_MIN;
void dfs(int deep,int st,int cnt)
{
	if(st==n)
	{
		if(cnt>ans)
		{
			ans=cnt;
		}
		return;
	}
	for(int i=st;i<n;i++)
	{
		int s=0;
		for(int j=st;j<=i;j++)
		{
			s=(s^(a[j]));
		}
		if(s==x)
		{
			dfs(deep+1,i+1,cnt+1);
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
