#include<bits/stdc++.h>
using namespace std;

int n,k,a[500005],cnt,ans;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]==1) cnt++;
	}
	if(k==0&&cnt==n)
	{
		if(n==1) cout<<0;
		else cout<<n/2;
		return 0;
	}
	if(k==0)
	{
		int nw=1;
		while(nw<=n)
		{
			if(a[nw]==0) ans++;
			if(a[nw]&&a[nw+1]) ans++,nw++;
			nw++;
		}
		cout<<ans;
		return 0;
	}
	if(k==1)
	{
		int nw=1;
		cout<<cnt;
		return 0;
	}
	return 0;
}
