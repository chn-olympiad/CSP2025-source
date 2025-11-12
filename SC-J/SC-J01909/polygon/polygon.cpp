#include<bits/stdc++.h>
using namespace std;
long long n,z[6000],ans;
void dfs(long long ma,long long sum,long long num,long long pl,bool b)
{
	if(pl>n) return;
	if(b&&num>2&&sum>2*ma) 
	{
		ans++;
	}
	dfs(z[pl],sum+z[pl],num+1,pl+1,1);
	dfs(ma,sum,num,pl+1,0);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int q=0;q<n;q++)
	{
		cin>>z[q];
	}
	sort(z,z+n);
	dfs(0,0,0,0,0);
	cout<<ans%998244353;
	return 0;
 } 
/*
5
2 2 3 8 10
*/