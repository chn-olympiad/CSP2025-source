#include<bits/stdc++.h>
using namespace std;
long long n,a[5050],ans,l,r,sum,k;
void dfs(int i,int k,long long sum,int f)
{
	sum+=a[i];
	if(sum>f*2&&k>=3) ans++;
	for(int j=i+1;j<=n;j++)
	{
		if(f<a[j]) dfs(j,k+1,sum,a[j]);
		else dfs(j,k+1,sum,f);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n-3;i++) {
		dfs(i,1,0,a[i]);
	}
	cout<<(ans+1)%998244353;
	return 0;
}
