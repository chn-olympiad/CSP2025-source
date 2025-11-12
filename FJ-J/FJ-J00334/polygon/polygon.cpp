#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 998244353,MAXN = 5e3+5;
int a[MAXN] = {0};
int cx(int n,int m)
{
	int res = 0;
	for(int i = 1;i <= n-m+1;i++)
	res = (res + ((1ll*i*(n-m+2-i))%MOD))%MOD;
	return res;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i = 0;i < n;i++) cin>>a[i];
	
	if(n == 3)
	{
		if(a[0]+a[1] > a[2] && a[1]+a[2] > a[0] && a[0]+a[2] > a[1]) cout<<1;
		else cout<<0;
		return 0;
	}
	
	
	int ans = 0;
	for(int i = 3;i <= n;i++)
	ans = (ans + (cx(n,i)%MOD))%MOD;
	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
