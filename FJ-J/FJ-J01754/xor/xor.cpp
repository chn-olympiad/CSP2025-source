#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ioimprove(); ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE(x); freopen(x".in","r",stdin);freopen(x".out","w",stdout);
int n,k,a[514514],sum[514514],cnt = 1,mp[514514];
signed main()
{
	FILE("xor");
	ioimprove();
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i],sum[i] = sum[i - 1] ^ a[i];
	mp[0] = 1;
	for(int i = 1;i <= n;i++)
	{
		if(mp[sum[i] ^ k] == cnt) cnt++;
		mp[sum[i]] = cnt;
	}
	cout<<cnt - 1;
	
	return 0;
}
