#include<bits/stdc++.h>
using namespace std;
int n,k,sum,ans;
map<int,bool>mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	mp[0]=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		sum^=x;
		if(mp[sum^k])
		{
			ans++;
			sum=0;
			mp.clear();
			mp[0]=1;
		}
		else
			mp[sum]=1;
	}
	cout<<ans;
	return 0;
}
