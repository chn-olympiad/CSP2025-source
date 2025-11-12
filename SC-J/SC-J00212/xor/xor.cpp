#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
map<int,int> mp;
int a[N];
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k; cin >>n >>k;
	for(int i=1;i<=n;i++) cin >>a[i];
	int x=0,ans=0; mp[0]++;
	for(int i=1;i<=n;i++)
	{
		x^=a[i];
		if(mp[x^k]>0)
		{
			ans++; mp.clear();
			mp[0]++; x=0;
		} 
		else mp[x]++;
	}
	cout <<ans;
	return 0;
}