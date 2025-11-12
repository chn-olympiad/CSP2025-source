#include<bits/stdc++.h>
using namespace std;
int a[100005];
int v[100005];
int s[100005];
int ans;
int n;
void dfs(int z,int cnt,int k)
{
	if(z>=k)
	{
		if(cnt>a[k])
		{
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=0;i<=1;i++)
	{
		if(v[z]==0&&i==1)
		{
			v[z]=1;
			dfs(z+1,cnt+a[z],k);
			v[z]=0;
		}
		else
		{
			dfs(z+1,cnt,k);
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
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		dfs(1,0,i);
	}
	cout<<ans;
	return 0;
} 
