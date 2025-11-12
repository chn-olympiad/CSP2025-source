#include<bits/stdc++.h>
#define int long long
using namespace std;
string test;
int c[505],p[505];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,ans=0;
	cin>>n>>m>>test;
	test=" "+test;
	for(int i=1;i<=n;i++) cin>>c[i],p[i]=i;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(i-1-cnt>=c[p[i]]||test[i]=='0') continue;
			else cnt++;
		}
		if(cnt>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans%998244353<<'\n';
	return 0;
}

