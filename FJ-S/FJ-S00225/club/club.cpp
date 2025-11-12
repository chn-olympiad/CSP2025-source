#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001],c[100001],f[5];
int t,n;
long long sum,maxa=-211212;
void dfs(int x)
{
	if(x==n+1)
	{
		maxa=max(sum,maxa);
	}
	if(f[2]<n/2)
	{
		f[2]++;
		sum+=b[x];
		dfs(x+1);
		f[2]--;
		sum-=b[x];
	}
	if(f[1]<n/2)
	{
		f[1]++;
		sum+=a[x];
		dfs(x+1);
		f[1]--;
		sum-=a[x];
	}
	if(f[3]<n/2)
	{
		f[3]++;
		sum+=c[x];
		dfs(x+1);
		f[3]--;
		sum-=c[x];
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	cin>>t;
	while(t--)
	{
		maxa=0;
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];	
		}
		dfs(1);
		cout<<maxa;
	}
} 
