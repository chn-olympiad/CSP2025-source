#include<bits/stdc++.h>
using namespace std;
int n,a[5000];
long long cnt;
void dfs(int x,long long ans,int ma,int c)
{
	if(x>n)return;
	if(ans>2*ma&&c>2)
	{
		cnt++;
	}
	if(a[x]<ma)dfs(x+1,ans+a[x],ma,c+1);
	else dfs(x+1,ans+a[x],a[x],c+1);
	dfs(x+1,ans,ma,c);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n-2;i++)dfs(i,a[i],a[i],1);
	cout<<cnt%998244353;
	return 0;
}
