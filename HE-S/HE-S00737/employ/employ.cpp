#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510,mod=998244353;
int n,m;
char c;
int a[N],b[N],cnt[N];
int z,op=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>c,a[i]=c-'0';
		if(a[i]!=1) op=0;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>b[i];
		if(b[i]==0) ++z;
	}
	ll ans=1;
	if(op)
	{
		if(n-z<m) cout<<0;
		else{
			for(int i=1;i<=m;++i) ans=ans*i%mod;
			cout<<ans;
		}
	}else
	{
		sort(b+1,b+n+1);
		bool x=1;
		for(int i=1;i<=n;++i) cnt[i]=cnt[i-1]+(a[i]==0);
		for(int i=1;i<=n;++i)
		{
			if(b[i]>cnt[i]){x=0;break;}
		}
		if(x){cout<<0;return 0;}
		
	}
	return 0;
}
