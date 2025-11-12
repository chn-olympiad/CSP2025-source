#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,ans,las;
int a[N],sum[N];
map <int,int> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum[i]=sum[i-1]^a[i];
	mp[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(mp.count(k^sum[i]))
			if(mp[k^sum[i]]+1>las) ans++,las=i;
		mp[sum[i]]=i;
	}
	printf("%d",ans);
	return 0;
}
