#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5001],sum=0,n;
void dfs(int start,int x,int ans,int maxn,int geshu)
{ 
	geshu++;
	if (geshu>=3&&ans>maxn*2)
		{
		sum++;
		sum%=998244353;
		}
	for (int i=x+1;i<=n;i++)
		dfs(start,i,ans+a[i],max(maxn,a[i]),geshu);
	return;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	//sort(a+1,a+1+n);
	for (int i=1;i<=n-2;i++)
		dfs(i,i,a[i],a[i],0);
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
