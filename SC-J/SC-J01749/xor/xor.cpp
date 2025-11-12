#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,k;
int a[maxn];//,dp[1010][1010];//dp[i][j]表示从i到j区间的
//最大值 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	if(flag) cout<<n/k;
	return 0;
}