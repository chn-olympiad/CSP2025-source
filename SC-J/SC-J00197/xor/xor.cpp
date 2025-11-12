#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,k,cnt;
int f[N],sum[N],a[N];
map<int,int> tong;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
		cin>>a[i],sum[i]=sum[i-1]^a[i];
	for(int i=1;i<=n;i++)
	{
		if(tong.count(k^sum[i]) || k == sum[i]) 
			f[i] = f[tong[k^sum[i]]] + 1;
		f[i] = max(f[i],f[i-1]);
		tong[sum[i]] = i;
	}
	cout<<f[n];
	return 0;
}