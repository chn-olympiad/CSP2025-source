#include<bits/stdc++.h>
using namespace std;
int a[200100];
int n,k;
long long ans=0;
void dfs(int l,int k1,long long sum,int h,int xo)
{
	if(h==1)
	{
		ans=max(ans,sum);
		return;
	}
	int r=l+k1;
	if(r>=n)
	{
		r=n;
		h=1;
	}
	if(xo!=-1)
	{
		int xo1=xo^a[r];
		if(xo1==k)dfs(r+1,0,sum+1,h,-1);
		else
		dfs(l,k1+1,sum,h,xo);
	}
	if(xo==-1)
	{
		xo=a[l];
		if(xo==k)dfs(r+1,0,sum+1,h,-1);
		else
		dfs(l,k1+1,sum,h,xo);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f=0,d=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1)f=1;
	}
	if(f==0)
	{
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++)
		dfs(i,0,0,0,-1);
	cout<<ans;
	return 0;
} 
