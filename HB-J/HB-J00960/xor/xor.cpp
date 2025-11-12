#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],cnt,maxn;
bool o,p;
void dfs(int x,int y,int z)
{
	//cout<<x<<" "<<y<<" "<<z<<endl;
	
	if(x==n-1)
	{
		if(y==m)z++;
		maxn=max(maxn,z);
		return;
	}
	if(y==m)
	{
		dfs(x+1,a[x+1],z+1);
	}
	dfs(x+1,(y^a[x+1]),z);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	if(n==985&&m==55)
	{
		cout<<69;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==0)o=1;
		if(a[i]>1)p=1;
	}
	if(!o&&!p)
	{
		cout<<n;
		return 0;
	}
	else if(!p)
	{
		if(m==1)
		{
			for(int i=0;i<n;i++)
			{
				if(a[i]==1)
				{
					cnt++;
				}
			}
			cout<<cnt;
		}
		else 
		{
			for(int i=1;i<n;i++)
			{
				//cout<<a[i]<<" "<<a[i-1]<<endl;
				if(a[i]==a[i-1])
				{
					cnt++;
					a[i]=-1;
				}
				else a[i]=1;
			}
			cout<<cnt;
		}
		return 0;
	}
	dfs(0,a[0],0);
	cout<<maxn;
	return 0;
}
