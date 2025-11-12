#include<bits/stdc++.h>
using namespace std;
int T;
int a[200005][5];
int c[200005][5];
int b[5];
int n;
int m;
int ans=0;
void dfs(int k,int sum)
{
	if(k>n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(b[i]==m)
		{
			continue;
		}
		else if(c[k][i]==0)
		{
			b[i]++;
			c[k][i]=1;
			dfs(k+1,sum+a[k][i]);
			b[i]--;
			c[k][i]=0;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		m=n/2;
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
