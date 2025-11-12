#include<bits/stdc++.h>
using namespace std;
const int N=5010,mod=998244353;
int n,a[N],ans;
void dfs(int dep,int lst,int sum,int m)
{
	if(dep>=m)
	{
		if(sum>a[lst]*2) ans=(ans+1)%mod;
		return;
	}
	for(int i=lst+1;i<=n;i++)
		dfs(dep+1,i,sum+a[i],m);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++) 
		dfs(0,0,0,i);
	cout<<ans<<endl;
	return 0;
}
