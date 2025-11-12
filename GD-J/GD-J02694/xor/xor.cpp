#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,cnt=0;
int a[N];
unordered_map<int,int> mp;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	int k=0,last=1;
	mp[0]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		k=k^a[i];
		if(mp[(k^m)]>=last)
		{
			cnt++;
			last=i+1;
		}
		mp[k]=i+1;
//		cout<<k<<" "<<cnt<<" "<<last<<'\n';
	}
	cout<<cnt;
	return 0;
}
