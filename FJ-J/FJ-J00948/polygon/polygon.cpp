#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
bool v[5005];
void dfs(int k,int s,int r,int t)
{
	if(k==r)
	{
		if(t>a[s]*2)
		{
			ans++;
		}
		return;
	}	
	for(int i=s;i<=n;i++)
	{
		if(v[i]==0)
		{
			int p=t+a[i];
			v[i]=1;
			dfs(k+1,i,r,p);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		dfs(0,1,i,0);
	}
	int tt=ans%998%244%353;
	cout<<tt;
	return 0;
}
