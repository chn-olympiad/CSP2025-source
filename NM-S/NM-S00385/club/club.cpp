#include<bits/stdc++.h>
using namespace std;
int num[100100][3];
int n,m;
int maxn=0;
int ans=0;
int pd[1000100];
int temp[1001001];
void dfs(int x)
{
	if(x==n+1)
	{
		for(int j=1;j<=n;j++)
			ans+=temp[j];
		maxn=max(maxn,ans);
		ans=0;

	}
	for(int i=0;i<3;i++)
	{
		if(pd[i]<m)
		{
			pd[i]++;
			temp[x]=num[x][i];
			dfs(x+1);
			pd[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>num[i][0]>>num[i][1]>>num[i][2];
		m=n/2;
		maxn=0;
		memset(pd,0,sizeof(pd));
		dfs(1);
		cout<<maxn<<endl;
	}
	return 0;
}
