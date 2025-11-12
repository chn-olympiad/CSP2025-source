#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[5005];
const long long mod=998224353;
long long ans=0;
void dfs(int f,int cnt,int num,int maxn)
{
	for(int i=f+1;i<=n;i++)
	{
		if(cnt>=2)
		{
			
			if(num+a[i]>2*max(maxn,a[i]))ans++;
		}
		ans%=mod;
		dfs(i,cnt+1,num+a[i],max(maxn,a[i]));
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n-2;i++)
	{
		dfs(i,1,a[i],a[i]);
	}
	cout<<ans%mod;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
