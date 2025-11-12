#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
bool b[5005];
long long md=998244353,ans;
void dfs(int cnt,int ma,int j)
{
	if(cnt>ma*2) 
	{
		if(ans==md) ans=0;
		ans++;
	}
	for(int i=j+1;i<=n;i++)
	{
		if(!b[i]) 
		{
			b[i]=1;
			dfs(cnt+a[i],max(ma,a[i]),i);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
