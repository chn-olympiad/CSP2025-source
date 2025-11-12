#include<bits/stdc++.h>
using namespace std;
int n,a[5010],maxx,s[5010],ans,mod=998244353;
bool v[5010];
void dfs(int sum,int zd,int p,int xh)
{
	
	if(p>=3)
	{
		if(sum>2*zd)
		ans++;
		ans%=mod;
	}
	if(p==n)
	return ;
	for(int i=xh;i<=n;i++)
		if(!v[i])
		{
			v[i]=true;
			dfs(sum+a[i],max(zd,a[i]),p+1,i);
			v[i]=false;
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
	dfs(0,0,0,1);
	cout<<ans;
	return 0;
}
//12 1 1 1 1 1 1 1 1 1 1 1 1
