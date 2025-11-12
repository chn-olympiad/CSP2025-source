#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
int n,k,ans,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)a[i]=a[i]^a[i-1];
	for(int i=0;i<=n;i++)
	{
		if(m[a[i]^k]==1)
		{
			ans++;
			m.clear();
		}
		m[a[i]]=1;
	}
	cout<<ans;
	return 0;
}
