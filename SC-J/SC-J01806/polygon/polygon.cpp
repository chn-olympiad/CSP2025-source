#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long num[100005];
long long cnt=0;
long long n;
void dfs(long long m,long long t)
{
	if(t>n)return;
	if(t>=3&&m>(2*a[t]))
	{
		cnt++;
		cnt%=998244353;
	}
	for(long long i=t+1;i<=n;i++)dfs(m+a[i],i);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0);
	cout<<cnt;
	return 0;
}