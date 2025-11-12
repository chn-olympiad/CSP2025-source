#include<bits/stdc++.h>
using namespace std;
long long a[5010],path[5010],n,ans=0;
bool v[5010];
void dfs(int lastp,int cnt,int kn,long long sum)
{
	if(cnt>kn)
	{
		if(path[cnt-1]*2<sum)
		{
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=lastp+1;i<=n;i++)
	{
		path[cnt]=a[i];
		v[i]=true;
		dfs(i,cnt+1,kn,sum+a[i]);
		v[i]=false;
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		dfs(0,1,i,0);
	cout<<ans;
    return 0;
}

