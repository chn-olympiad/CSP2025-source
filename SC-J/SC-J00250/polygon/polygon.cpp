#include<bits/stdc++.h>
using namespace std;
int n;
int ans=0;
int a[500005];
int o[500005];
bool f[500005];
void dfs(int x,int k)
{
	if(x==0)
	{
		int l=-1,s;
		for(int i=1;i<=k;i++)
		{
			l=max(l,o[i]);
			s+=o[i];
		}
		if(s>l*2)
		{
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			o[x]=a[i];
			dfs(x-1,k);
			f[i]=0;
		}
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int ma=-1,s=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		s+=a[i];
		ma=max(ma,a[i]);
	}
	int u=0;
	if(ma*2<s) ans++;
	if(n<=3) 
	{
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	int liu=2;
	for(int i=3;i<n;i++)
	{
		ans=0;
		dfs(i,i);
		u+=(ans/(liu*i));
		cout<<ans<<endl;
	}
	cout<<u;
	return 0;
}
