#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,s1[N],s2[N],s3[N],maxn=0;

void dfs(int sum,int now,int a1,int a2,int a3)
{
	if(now==n+1)
	{
		maxn=max(maxn,sum);
		return;
	}
	if(a1<n/2)
		dfs(sum+s1[now],now+1,a1+1,a2,a3);
	if(a2<n/2)
		dfs(sum+s2[now],now+1,a1,a2+1,a3);
	if(a3<n/2)
		dfs(sum+s3[now],now+1,a1,a2,a3+1);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>s1[i]>>s2[i]>>s3[i];
		dfs(0,1,0,0,0);
		cout<<maxn<<'\n';
	}
	return 0;
}


















