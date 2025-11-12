#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,ans;
void solve()
{
	for(int i=1;i<=n;++i)
	{
		if(a[i]==0)
		{
			++ans;
			continue;
		}
		if(a[i]==a[i+1])
		{
			++ans;
			++i;
		}
	}
	cout<<ans<<"\n";
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	if(k==0)
		solve();
	else
	{
		for(int i=1;i<=n;++i)
			if(a[i]==k)
				++ans;
		cout<<ans<<"\n";
	}
	return 0;
}
