#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100010][4];
int b[100010];
int h[4];
long long mx;
long long ans;
void dfs(int x)
{
	if(x==n+1)
	{
		mx=max(mx,ans);
		//cout<<ans<<endl;
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(h[i]<n/2)
		{
			h[i]++;
			ans+=a[x][i];
			//cout<<i;
			dfs(x+1);
			h[i]--;
			ans-=a[x][i];
		}
		
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		
		for(int i=1;i<=3;i++)
		{
			h[i]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		ans=0;
		mx=0;
		if(n<=16)
		{
			dfs(1);
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1,greater<int>());
			for(int i=1;i<=n/2;i++)
			{
				mx+=b[i];
			}
		}
		cout<<mx<<endl;
	}
	return 0;
}
