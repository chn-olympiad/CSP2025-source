#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010];
map<int,bool> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]^=a[i-1];
	int cnt=0;
	mp[k]=1;
	for(int i=1;i<=n+1;i++)
	{
		if(mp[a[i]]==1)
		{
			cnt++;
			mp.clear();
		}
		mp[a[i]^k]=1;
	}
	cout<<cnt<<'\n';
	return 0;
}
