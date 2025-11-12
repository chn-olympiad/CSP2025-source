#include<bits/stdc++.h>
using namespace std; 
const int N=5e5+5;
int n,k;
int a[N];
int sum[N];
map<int,int> mp;
map<int,int> pos;
int f(int l,int r)
{
	return sum[r]^sum[l-1];
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=a[i]^sum[i-1];
	}
	int la=1;
	int cnt=0; 
	mp[0]++;
	for(int i=1;i<=n;i++)
	{
		if(mp[k^sum[i]]>0)
		{
			cnt++;
			mp.clear();
		}
		mp[sum[i]]++;
	}
	cout<<cnt;
	return 0;
}
